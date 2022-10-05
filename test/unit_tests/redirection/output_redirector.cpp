// My headers
#include "../include/progressbar/progress_bar.hpp"
#include "../include/redirection/output_redirector.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <iostream>
#include <thread>

TEST_CASE( "Testing OutputRedirector class" )
{
  std::string filename = "output.txt";
  osm::OutputRedirector redirector( filename );

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