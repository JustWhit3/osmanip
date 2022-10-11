// My headers
#include "../include/progressbar/progress_bar.hpp"
#include "../include/redirection/output_redirector.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <iostream>
#include <thread>

// Helper function
void cleanUp()
{
  // Delete any created files
}

TEST_CASE( "Testing OutputRedirector class" )
{
  osm::OutputRedirector redirector;
  std::string test_filename = "test_output_redirector.txt";

  //====================================================
  //     Testing getters, setters and constructor
  //====================================================
  TEST_SUITE_BEGIN( "Setters, getters and constructors." );

  SUBCASE( "Testing naked getters and constructor." )
  {
    CHECK_EQ( redirector.getFilename(), osm::OutputRedirector::DEFAULT_FILENAME );
  }

  SUBCASE( "Testing setters and getters with initialized values." )
  {
    osm::OutputRedirector init_redirector( test_filename );

    CHECK_NE( init_redirector.getFilename(), osm::OutputRedirector::DEFAULT_FILENAME );
    CHECK_EQ( init_redirector.getFilename(), test_filename );

    init_redirector.setFilename( osm::OutputRedirector::DEFAULT_FILENAME );

    CHECK_NE( init_redirector.getFilename(), test_filename );
    CHECK_EQ( init_redirector.getFilename(), osm::OutputRedirector::DEFAULT_FILENAME );
  }

  TEST_SUITE_END();

  redirector.setFilename(test_filename);

  TEST_SUITE_BEGIN( "File creation and modification." );

  //====================================================
  //     Testing "touch" method
  //====================================================
  SUBCASE( "Testing touch method." )
  {

  }

  //====================================================
  //     Testing "read_file" and "write_to_file" methods
  //====================================================
  SUBCASE( "Testing read_file and write_to_file methods." )
  {
  }

  //====================================================
  //     Testing "clear_buffer" method
  //====================================================
  SUBCASE( "Testing clear_buffer method." )
  {
  }

  //====================================================
  //     Testing "redirect_output" method
  //====================================================
  SUBCASE( "Testing redirect_output method." )
  {
  }

  TEST_SUITE_END();

  TEST_SUITE_BEGIN( "Other methods." );

  //====================================================
  //     Testing "begin" and "end" methods
  //====================================================
  SUBCASE( "Testing begin and end methods." )
  {
  }

  //====================================================
  //     Testing "flush" method
  //====================================================
  SUBCASE( "Testing flush method." )
  {
  }

  TEST_SUITE_END();

  std::string filename = "output.txt";
  //   osm::OutputRedirector redirector( filename );

  // Normal percentage bar.
  osm::ProgressBar<int> percentage_bar;
  percentage_bar.setMin( 5 );
  percentage_bar.setMax( 46 );
  percentage_bar.setStyle( "indicator", "%" );

  // Redirect output
  redirector.begin();

  std::cout << "This is a normal percentage bar: "
            << "\n";
  for( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
    // Flush the buffer at the start of each loop
    redirector.flush();

    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    percentage_bar.update( i );
    // Do some operations...
  }

  // Return output to std::cout
  redirector.end();
}