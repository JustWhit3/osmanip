//====================================================
//     Headers
//====================================================

// My headers
#include <include/utility/options.hpp>
#include <include/utility/iostream.hpp>
#include <include/progressbar/progress_bar.hpp>
#include <include/progressbar/multi_progress_bar.hpp>
#ifdef _WIN32
#  include <include/utility/windows.hpp>
#endif

// STD headers
#include <chrono>
#include <thread>

//====================================================
//     Percentage bar
//====================================================
void perc_bars()
{
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     PERCENTAGE BARS"
            << "\n"
            << "======================================================"
            << "\n\n";

  // Normal percentage bar.
  osm::ProgressBar<int32_t> percentage_bar;
  percentage_bar.setMin( 5 );
  percentage_bar.setMax( 46 );
  percentage_bar.setStyle( "indicator", "%" );

  osm::cout << "This is a normal percentage bar: "
            << "\n";
  for( int32_t i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
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
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    percentage_bar_2.update( i );
    // Do some operations...
  }
  osm::cout << "\n\n";

  // Percentage bar with time consuming info:
  percentage_bar.resetMessage();
  percentage_bar.setStyle( "indicator", "%" );

  osm::cout << "This is a percentage bar with time consuming info: "
            << "\n";
  for( int32_t i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
    percentage_bar.setBegin();
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    percentage_bar.update( i );
    // Do some operations...
    percentage_bar.setEnd();
  }
  osm::cout << "\n"
            << "Time needed to complete the previous loop: "
            << percentage_bar.getTime() << " ms."
            << "\n\n";

  // Percentage bar with estimated time left:
  percentage_bar.setMin( 2 );
  percentage_bar.setMax( 121 );
  percentage_bar.setRemainingTimeFlag( "on" );
  percentage_bar.resetRemainingTime();

  osm::cout << "This is a percentage bar with time-remaining info: "
            << "\n";
  for( int32_t i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    percentage_bar.update( i );
    // Do some operations...
  }
  osm::cout << "\n\n";
}

//====================================================
//     Loading bar
//====================================================
void load_bars()
{
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     LOADING BARS                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  osm::ProgressBar<int32_t> loading_bar;
  loading_bar.setMin( 3 );
  loading_bar.setMax( 25 );
  loading_bar.setStyle( "loader", "#" );
  loading_bar.setBrackets( "[", "]" );

  osm::cout << "This is a normal loading bar: "
            << "\n";
  for( int32_t i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
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
  for( int32_t i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
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
  for( int32_t i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    loading_bar.update( i );
    // Do some operations...
  }
  osm::cout << "\n\n";
}

//====================================================
//     Mixed bar
//====================================================
void mixed_bars()
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
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
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
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
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
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    mixed_bar.update( i );
    // Do some operations...
  }
  osm::cout << "\n\n";
}

//====================================================
//     Multi bars
//====================================================
void multi_bars()
{
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     MULTI PROGRESS BARS                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  osm::cout << "These are 3 progress bars printed simultaneously: "
            << "\n\n\n";

  osm::ProgressBar<int32_t> prog_int;
  prog_int.setMin( 0 );
  prog_int.setMax( 60 );
  prog_int.setStyle( "complete", "%", "#" );
  prog_int.setBrackets( "[", "]" );
  prog_int.setMessage( "Installing..." );
  prog_int.setColor( "red" );

  osm::ProgressBar<int32_t> prog_int_2( 5, 25 );
  prog_int_2.setStyle( "complete", "%", "■" );
  prog_int_2.setBrackets( "{", "}" );
  prog_int_2.setMessage( "Processing..." );
  prog_int_2.setColor( "purple" );

  osm::ProgressBar<float> prog_float;
  prog_float.setMin( 0.1f );
  prog_float.setMax( 5.8f );
  prog_float.setStyle( "complete", "%", "#" );
  prog_float.setBrackets( "[", "]" );
  prog_float.setMessage( "Downloading..." );
  prog_float.setColor( "yellow" );

  auto bars = MultiProgressBar( prog_int, prog_int_2, prog_float );

  auto job1 = [ &bars, &prog_int ]()
  {
    for( int32_t i = prog_int.getMin(); i < prog_int.getMax(); i++ )
    {
      bars.for_one( 0, osm::updater {}, i );
      std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    }
  };

  auto job2 = [ &bars, &prog_int_2 ]()
  {
    for( int32_t i = prog_int_2.getMin(); i < prog_int_2.getMax(); i++ )
    {
      bars.for_one( 1, osm::updater {}, i );
      std::this_thread::sleep_for( std::chrono::milliseconds( 60 ) );
    }
  };

  auto job3 = [ &bars, &prog_float ]()
  {
    for( float i = prog_float.getMin(); i < prog_float.getMax(); i += 0.1f )
    {
      bars.for_one( 2, osm::updater {}, i );
      std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
    }
  };

  std::thread first_job( job1 );
  std::thread second_job( job2 );
  std::thread third_job( job3 );

  first_job.join();
  second_job.join();
  third_job.join();

  osm::cout << "\n\n\n";
}

//====================================================
//     Progress spinner
//====================================================
void progress_spinner()
{
  osm::cout << "\n"
            << "======================================================"
            << "\n"
            << "     PROGRESS SPINNER                                    "
            << "\n"
            << "======================================================"
            << "\n\n";

  // Integer progress spinner.
  osm::ProgressBar<int32_t> spinner;
  spinner.setMin( 2 );
  spinner.setMax( 33 );
  spinner.setStyle( "spinner", "/-\\|" );

  osm::cout << "This is a progress spinner: "
            << "\n";
  for( int32_t i = spinner.getMin(); i < spinner.getMax(); i++ )
  {
    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
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

    std::this_thread::sleep_for( std::chrono::milliseconds( 30 ) );
    spinner_float.update( i );
    // Do some operations...
  }
  osm::cout << "\n\n";
}

//====================================================
//     Main
//====================================================
int main()
{
#ifdef _WIN32
  osm::enableANSI();
#endif

  static bool test_perc_bars = true;
  static bool test_load_bars = true;
  static bool test_mixed_bars = true;
  static bool test_multi_bars = true;
  static bool test_prog_spinners = true;

  osm::OPTION( osm::CURSOR::OFF );

  osm::cout << "======================================================"
            << "\n"
            << "     OUTPUT REDIRECTION                               "
            << "\n"
            << "======================================================"
            << "\n\n"
            << std::flush;

  // Use default filename or set your own
  osm::redirout.setFilename( "example_output.txt" );

  osm::cout << osm::feat( osm::col, "lt cyan" )
            << "Redirecting example output to '"
            << osm::feat( osm::sty, "underlined" ) << osm::feat( osm::col, "white" )
            << osm::redirout.getFilename()
            << osm::feat( osm::rst, "underlined" ) << osm::feat( osm::col, "lt cyan" ) << "'."
            << osm::feat( osm::rst, "all" ) << std::flush;

  // Begin redirecting the output stream to a file
  osm::redirout.begin();

  osm::cout << "------------------------------------\n"
            << "Progress bars, with logging!\n"
            << "------------------------------------\n";

  // End the redirection and return output to console
  osm::redirout.end();

  /** Important note: ==============================================================
   *    When in a loop, you must update file with the newest data by calling flush()
   *    once every iteration, otherwise the data will not be properly formatted when
   *    it is written to the file (it will print every step and look ugly).
   *    There's probably a way around this...
   * ================================================================================*/

  osm::cout << osm::feat( osm::col, "white" ) << "\n-- ";

  if( test_perc_bars )
  {
    osm::cout << "Running percentage bars example... " << std::flush;
    osm::redirout.begin();
    perc_bars();
    osm::redirout.end();
    osm::cout << osm::feat( osm::col, "lt green" ) << "Done." << std::flush;
  }
  else
  {
    osm::cout << osm::feat( osm::col, "dk gray" ) << osm::feat( osm::sty, "italics" )
              << "Skipping percentage bars example."
              << osm::feat( osm::rst, "all" ) << std::flush;
  }

  osm::cout << osm::feat( osm::col, "white" ) << "\n-- ";

  if( test_load_bars )
  {
    osm::cout << "Running loading bars example... " << std::flush;
    osm::redirout.begin();
    load_bars();
    osm::redirout.end();
    osm::cout << osm::feat( osm::col, "lt green" ) << "Done." << std::flush;
  }
  else
  {
    osm::cout << osm::feat( osm::col, "dk gray" ) << osm::feat( osm::sty, "italics" )
              << "Skipping loading bars example."
              << osm::feat( osm::rst, "all" ) << std::flush;
  }

  osm::cout << osm::feat( osm::col, "white" ) << "\n-- ";

  if( test_mixed_bars )
  {
    osm::cout << "Running mixed bars example... " << std::flush;
    osm::redirout.begin();
    mixed_bars();
    osm::redirout.end();
    osm::cout << osm::feat( osm::col, "lt green" ) << "Done." << std::flush;
  }
  else
  {
    osm::cout << osm::feat( osm::col, "dk gray" ) << osm::feat( osm::sty, "italics" )
              << "Skipping mixed bars example."
              << osm::feat( osm::rst, "all" ) << std::flush;
  }

  osm::cout << osm::feat( osm::col, "white" ) << "\n-- ";

  if( test_multi_bars )
  {

    osm::cout << "Running multi bars example... " << std::flush;
    osm::redirout.begin();
    multi_bars();
    osm::redirout.end();
    osm::cout << osm::feat( osm::col, "lt green" ) << "Done." << std::flush;
  }
  else
  {
    osm::cout << osm::feat( osm::col, "dk gray" ) << osm::feat( osm::sty, "italics" )
              << "Skipping multi bars example."
              << osm::feat( osm::rst, "all" ) << std::flush;
  }

  osm::cout << osm::feat( osm::col, "white" ) << "\n-- ";

  if( test_prog_spinners )
  {

    osm::cout << "Running progress spinners example... " << std::flush;
    osm::redirout.begin();
    progress_spinner();
    osm::redirout.end();
    osm::cout << osm::feat( osm::col, "lt green" ) << "Done." << std::flush;
  }
  else
  {
    osm::cout << osm::feat( osm::col, "dk gray" ) << osm::feat( osm::sty, "italics" )
              << "Skipping progress spinners example."
              << osm::feat( osm::rst, "all" ) << std::flush;
  }

  osm::redirout.begin();
  osm::cout << "\n"
               "------------------------------------\n"
               "Example complete!\n"
               "------------------------------------\n";
  osm::redirout.end();

  osm::cout << '\n'
            << osm::feat( osm::col, "lt cyan" )
            << "Open `"
            << osm::feat( osm::col, "white" ) << osm::feat( osm::sty, "underlined" )
            << osm::redirout.getFilename()
            << osm::feat( osm::rst, "underlined" ) << osm::feat( osm::col, "lt cyan" )
            << "` to view output.\n\n"
            << osm::feat( osm::rst, "all" ) << std::flush;

  osm::OPTION( osm::CURSOR::ON );

#ifdef _WIN32
  osm::disableANSI();
#endif
}