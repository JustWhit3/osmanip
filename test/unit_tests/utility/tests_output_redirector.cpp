//====================================================
//     Headers
//====================================================

// My headers
#include "../../../include/utility/iostream.hpp"
#include "../../../include/progressbar/progress_bar.hpp"
#include "../../../include/utility/output_redirector.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <thread>
#include <filesystem>

//====================================================
//     Aliases
//====================================================
namespace fs = std::filesystem;

//====================================================
//     Global constants
//====================================================
const fs::path WORKING_DIR_PATH = fs::current_path();
const std::string TEST_FILENAME = "test_output_redirector.txt";

//====================================================
//     Function prototypes
//====================================================

//Helper functions
bool delete_file( const std::string & filename );
bool file_exists( const std::string & filename );
fs::path find_file( const std::string & filename );
std::string read_file( const std::string & filename );

//Test functions
void test_perc_bars( osm::OutputRedirector & redirector );
void test_load_bars( osm::OutputRedirector & redirector );
void test_mixed_bars( osm::OutputRedirector & redirector );
void test_progress_spinner( osm::OutputRedirector & redirector );

//====================================================
//     Testing OutputRedirector class
//====================================================
TEST_CASE( "Testing OutputRedirector class" )
{
  osm::OutputRedirector redirector;
  std::string default_filename = redirector.getFilename();

  fs::path default_filepath = WORKING_DIR_PATH;
  default_filepath /= default_filename;

  // If the file still exists for some reason, delete it before testing.
  delete_file( TEST_FILENAME );

  //====================================================
  //     Testing getters, setters, and constructor
  //====================================================
  TEST_SUITE_BEGIN( "Setters, getters and constructors." );

  SUBCASE( "Testing naked getters and constructor." )
   {
    CHECK_EQ( redirector.getFilename(), default_filename );
   }

  SUBCASE( "Testing setters and getters with initialized values." )
   {
    osm::OutputRedirector init_redirector( TEST_FILENAME );

    CHECK_NE( init_redirector.getFilename(), default_filename );
    CHECK_EQ( init_redirector.getFilename(), TEST_FILENAME );

    init_redirector.setFilename( default_filename );

    CHECK_NE( init_redirector.getFilename(), TEST_FILENAME );
    CHECK_EQ( init_redirector.getFilename(), default_filename );
   }

  TEST_SUITE_END();

  fs::path test_filepath = WORKING_DIR_PATH / TEST_FILENAME;

  TEST_SUITE_BEGIN( "File creation and modification." );

  //====================================================
  //     Testing "touch" method
  //====================================================
  SUBCASE( "Testing touch method." )
   {
    CHECK_EQ( file_exists( redirector.getFilename() ), false );

    redirector.touch();

    CHECK_EQ( file_exists( redirector.getFilename() ), true );
    CHECK_EQ( find_file( redirector.getFilename() ), default_filepath );
    CHECK_EQ( delete_file( redirector.getFilename() ), true );
    CHECK_EQ( file_exists( redirector.getFilename() ), false );

    redirector.setFilename( TEST_FILENAME );

    CHECK_EQ( file_exists( redirector.getFilename() ), false );

    redirector.touch();

    CHECK_EQ( find_file( redirector.getFilename() ), test_filepath );
    CHECK_EQ( delete_file( redirector.getFilename() ), true );
    CHECK_EQ( file_exists( redirector.getFilename() ), false );
   }

  TEST_SUITE_END();

  redirector.setFilename( TEST_FILENAME );

  TEST_SUITE_BEGIN( "Other methods." );

  //====================================================
  //     Testing "begin", "flush", and "end" methods
  //====================================================
  SUBCASE( "Testing begin, flush, and end methods." )
   {
    CHECK_THROWS_AS( redirector.end(), std::runtime_error );
//     CHECK_THROWS_AS( redirector.flush(), std::runtime_error );

    CHECK_NOTHROW( redirector.begin() );
    CHECK_THROWS_AS( redirector.begin(), std::runtime_error );

//     CHECK_NOTHROW( redirector.flush() );

    CHECK_NOTHROW( redirector.end() );
    CHECK_THROWS_AS( redirector.end(), std::runtime_error );
   }

  delete_file( redirector.getFilename() );

  TEST_SUITE_END();

  TEST_SUITE_BEGIN( "Output redirection." );

  //====================================================
  //     Testing "output redirection" feature
  //====================================================
  SUBCASE( "Testing normal output redirection." )
   {
    std::string test_redirection_str = "Testing \"output redirection\".";

    redirector.begin();
    osm::cout << test_redirection_str << std::flush;
    redirector.end();

    std::string file_contents = read_file( redirector.getFilename() );

    CHECK_EQ( file_contents, test_redirection_str );
    CHECK_NE( file_contents, "Not equal to " + test_redirection_str );

    std::ofstream cleared_file( redirector.getFilename(), std::fstream::trunc | std::fstream::out );

    CHECK_EQ( cleared_file.is_open(), true );
    cleared_file.close();
    file_contents = read_file( redirector.getFilename() );

    CHECK_EQ( file_contents, "" );

    std::string lorem_ipsum_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt "
                                  "ut labore et dolore magna aliqua. Fermentum et sollicitudin ac orci phasellus. Ut tortor "
                                  "pretium viverra suspendisse. Nunc aliquet bibendum enim facilisis gravida neque convallis "
                                  "a cras.\nPellentesque dignissim enim sit amet venenatis urna. At lectus urna duis convallis."
                                  "\nVolutpat sed cras ornare arcu dui. Congue mauris rhoncus aenean vel elit scelerisque "
                                  "mauris pellentesque pulvinar. Blandit.\nJusto eget magna fermentum iaculis eu non diam.\n"
                                  "Amet venenatis urna cursus eget nunc scelerisque.Ut placerat orci nulla pellentesque.";

    redirector.begin();
    osm::cout << lorem_ipsum_str;
    
    file_contents = read_file( redirector.getFilename() );

    CHECK_EQ( file_contents, lorem_ipsum_str );
    redirector.end();
   }

  delete_file( redirector.getFilename() );

  //====================================================
  //     Testing "progress bar" redirection
  //====================================================
  SUBCASE( "Testing normal progress bar redirection" )
   {
    redirector.begin();
    test_perc_bars( redirector );
    redirector.end();

    // Check output vs. static string
    std::string output_text = "\n"
                              "======================================================"
                              "\n"
                              "     PERCENTAGE BARS                                    "
                              "\n"
                              "======================================================"
                              "\n\n"
                              "This is a normal percentage bar: \n"
                              "100% \n"
                              "\n"
                              "This is a percentage bar with message and the /100 style: \n"
                              "100/100 processing... \n"
                              "\n"
                              "This is a percentage bar with time consuming info: \n"
                              "100% \n"
                              "\n"
                              "This is a percentage bar with time-remaining info: \n"
                              "100% [Estimated time left: 0m 0s]\n\n";

    std::string file_contents = read_file( redirector.getFilename() );
    CHECK_EQ( file_contents, output_text );
   }

  delete_file( redirector.getFilename() );

  SUBCASE( "Testing loading bar redirection" )
   {
    redirector.begin();
    test_load_bars( redirector );
    redirector.end();

    // Check output vs. static string
    std::string output_text = "\n"
                              "======================================================"
                              "\n"
                              "     LOADING BARS                                    "
                              "\n"
                              "======================================================"
                              "\n\n"
                              "This is a normal loading bar: \n"
                              "[#########################] \n"
                              "\n"
                              "This is a loading bar with message: \n"
                              "{#########################} processing... \n"
                              "\n"
                              "This is a loading bar with time-remaining info: \n"
                              "{#########################} [Estimated time left: 0m 0s]\n\n";

    std::string file_contents = read_file( redirector.getFilename() );
    CHECK_EQ( file_contents, output_text );
   }

  delete_file( redirector.getFilename() );

  SUBCASE( "Testing mixed progress bar redirection" )
   {
    redirector.begin();
    test_mixed_bars( redirector );
    redirector.end();

    // Check output vs. static string
    std::string output_text = "\n"
                              "======================================================"
                              "\n"
                              "     FULL PROGRESS BARS                                    "
                              "\n"
                              "======================================================"
                              "\n\n"
                              "This is a mixed progress bar: \n"
                              "[■■■■■■■■■■■■■■■■■■■■■■■■■] 100% elaborating... \n"
                              "\n"
                              "This is a mixed progress bar with color and time remaining info: \n"
                              "[■■■■■■■■■■■■■■■■■■■■■■■■■] 100% elaborating... [Estimated time left: 0m 0s]\n"
                              "\n"
                              "This is a mixed progress bar with two customized styles: \n"
                              "[>>>>>>>>>>>>>>>>>>>>>>>>>] 100|100 elaborating... \n\n";

    std::string file_contents = read_file( redirector.getFilename() );
    CHECK_EQ( file_contents, output_text );
   }

  delete_file( redirector.getFilename() );

  SUBCASE( "Testing progress spinner redirection" )
   {
    redirector.begin();
    test_progress_spinner( redirector );
    redirector.end();

    // Check output vs. static string
    std::string output_text = "\n"
                              "======================================================"
                              "\n"
                              "     PROGRESS SPINNER                                    "
                              "\n"
                              "======================================================"
                              "\n\n"
                              "This is a progress spinner: \n"
                              "/0 \n"
                              "\n"
                              "This is another progress spinner: \n"
                              "\\0 elaborating data... \n\n";

    std::string file_contents = read_file( redirector.getFilename() );
    CHECK_EQ( file_contents, output_text );
   }

  delete_file( redirector.getFilename() );

  TEST_SUITE_END();
}

//====================================================
//     Function definitions
//====================================================

// Finds a file and return its absolute path
bool file_exists( const std::string & filename )
 {
  namespace fs = std::filesystem;

  auto working_path = fs::current_path();

  return fs::exists( working_path /= filename );
 }

// Finds a file and return its absolute path
fs::path find_file( const std::string & filename )
 {
  namespace fs = std::filesystem;

  auto working_path = fs::current_path();

  // Search current directory first
  for( const auto & working_dir_entry: fs::recursive_directory_iterator( working_path ) )
   {
    if( working_dir_entry.is_regular_file() && working_dir_entry.path().filename() == filename )
     {
      return working_dir_entry.path();
     }
   }

  // Recursively search the entire dir
  for( const auto & dir_entry: fs::recursive_directory_iterator( working_path ) )
   {
    if( dir_entry.is_regular_file() && dir_entry.path().filename() == filename )
     {
      return dir_entry.path();
     }
   }

  return {};
 }

std::string read_file( const std::string & filename )
 {
  std::fstream fstream( filename );
  CHECK_EQ( fstream.is_open(), true );
  std::stringstream sstream;
  sstream << fstream.rdbuf();
  fstream.close();
  return sstream.str();
 }

bool delete_file( const std::string & filename )
 {
  return fs::remove( find_file( filename ) );
 }

void test_perc_bars( osm::OutputRedirector & redirector )
 {
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     PERCENTAGE BARS                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  // Normal percentage bar.
  osm::ProgressBar<int> percentage_bar;
  percentage_bar.setMin( 5 );
  percentage_bar.setMax( 46 );
  percentage_bar.setStyle( "indicator", "%" );

  osm::cout << "This is a normal percentage bar: "
            << "\n";
  for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    percentage_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  // Percentage bar with message and different style:
  osm::ProgressBar<float> percentage_bar_2( 1.2f, 4.4f );
  percentage_bar_2.setMessage( "processing..." );
  percentage_bar_2.setStyle( "indicator", "/100" );

  osm::cout << "This is a percentage bar with message and the /100 style: "
            << "\n";
  for( float i = percentage_bar_2.getMin(); i < percentage_bar_2.getMax(); i += 0.1f )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    percentage_bar_2.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  // Percentage bar with time consuming info:
  percentage_bar.resetMessage();
  percentage_bar.setStyle( "indicator", "%" );

  osm::cout << "This is a percentage bar with time consuming info: "
            << "\n";
  for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    

    percentage_bar.setBegin();
    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    percentage_bar.update( i );
    // Do some operations...
    percentage_bar.setEnd();
   }

  osm::cout << "\n\n";

  // Percentage bar with estimated time left:
  percentage_bar.setMin( 2 );
  percentage_bar.setMax( 121 );
  percentage_bar.setRemainingTimeFlag( "on" );
  percentage_bar.resetRemainingTime();

  osm::cout << "This is a percentage bar with time-remaining info: "
            << "\n";
  for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    percentage_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";
 }

void test_load_bars( osm::OutputRedirector & redirector )
 {
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     LOADING BARS                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  osm::ProgressBar<int> loading_bar;
  loading_bar.setMin( 3 );
  loading_bar.setMax( 25 );
  loading_bar.setStyle( "loader", "#" );
  loading_bar.setBrackets( "[", "]" );

  osm::cout << "This is a normal loading bar: "
            << "\n";
  for( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    loading_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  // Loading bar with message:
  loading_bar.resetBrackets();
  loading_bar.setMessage( "processing..." );
  loading_bar.setBrackets( "{", "}" );

  osm::cout << "This is a loading bar with message: "
            << "\n";
  for( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    loading_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  // Loading bar with time remaining info:
  loading_bar.setMin( 3 );
  loading_bar.setMax( 101 );
  loading_bar.resetMessage();
  loading_bar.setRemainingTimeFlag( "on" );
  loading_bar.resetRemainingTime();

  osm::cout << "This is a loading bar with time-remaining info: "
            << "\n";
  for( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    loading_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";
 }

void test_mixed_bars( osm::OutputRedirector & redirector )
 {
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     FULL PROGRESS BARS                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  osm::ProgressBar<float> mixed_bar( 0.1f, 3.8f );
  mixed_bar.setStyle( "complete", "%", "■" );
  mixed_bar.setBrackets( "[", "]" );
  mixed_bar.setMessage( "elaborating..." );

  osm::cout << "This is a mixed progress bar: "
            << "\n";
  for( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    mixed_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  mixed_bar.setColor( "red" );
  mixed_bar.setRemainingTimeFlag( "on" );
  mixed_bar.resetRemainingTime();

  osm::cout << "This is a mixed progress bar with color and time remaining info: "
            << "\n";
  for( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    mixed_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  mixed_bar.resetColor();
  mixed_bar.addStyle( "indicator", "|100" );
  mixed_bar.addStyle( "loader", ">" );
  mixed_bar.setStyle( "complete", "|100", ">" );
  mixed_bar.setRemainingTimeFlag( "off" );

  osm::cout << "This is a mixed progress bar with two customized styles: "
            << "\n";
  for( float i = mixed_bar.getMin(); i < mixed_bar.getMax(); i += 0.1f )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    mixed_bar.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";
 }

void test_progress_spinner( osm::OutputRedirector & redirector )
 {
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     PROGRESS SPINNER                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  // Integer progress spinner.
  osm::ProgressBar<int> spinner;
  spinner.setMin( 2 );
  spinner.setMax( 33 );
  spinner.setStyle( "spinner", "/-\\|" );

  osm::cout << "This is a progress spinner: "
            << "\n";
  for( int i = spinner.getMin(); i < spinner.getMax(); i++ )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    spinner.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";

  // Float progress spinner.
  osm::ProgressBar<float> spinner_float;
  spinner_float.setMin( 2.3f );
  spinner_float.setMax( 6.7f );
  spinner_float.setColor( "lt blue" );
  spinner_float.addStyle( "spinner", "|/_\\" );
  spinner_float.setStyle( "spinner", "|/_\\" );
  spinner_float.setMessage( "elaborating data..." );

  osm::cout << "This is another progress spinner: "
            << "\n";
  for( float i = spinner_float.getMin(); i < spinner_float.getMax(); i += 0.1f )
   {
    

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    spinner_float.update( i );
    // Do some operations...
   }
  osm::cout << "\n\n";
 }