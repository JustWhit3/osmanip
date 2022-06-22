//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include "../include/progressbar/progress_bar.hpp"
#include "../include/progressbar/multi_progress_bar.hpp"

//Extra headers
#include <doctest/doctest.h>

//STD headers
#include <sstream>

//====================================================
//     Global variables
//====================================================
osm::ProgressBar <int> bar1;
osm::ProgressBar <double> bar2;
osm::ProgressBar <float> bar3;
auto bars = osm::MultiProgressBar( bar1, bar2, bar3 );

//====================================================
//     Testing "size" method
//====================================================
TEST_CASE( "Testing the size method" )
 {
  CHECK_EQ( bars.size(), 3 );
 }

//====================================================
//     Testing "operator()" redefinition
//====================================================
TEST_CASE( "Testing the operator() redefinition in the updater struct" )
 {
  bar1.setMin( 0 );
  bar1.setMax ( 60 );
  bar1.setStyle( "indicator", "%" );

  static std::stringstream ss_multi, ss_normal;

  for( int i = bar1.getMin(); i < bar1.getMax(); i++ ) 
   {
    auto first_output_multi = [ &i ]( std::ostream& ){ bars.for_one( 0, osm::updater{}, i ); };
    auto first_output_normal = [ &i ]( std::ostream& ){ bar1.update( i ); };

    auto old_buffer = std::cout.rdbuf(nullptr);
    first_output_multi( ss_multi );
    first_output_normal( ss_normal );
    std::cout.rdbuf(old_buffer);

    CHECK_EQ( ss_multi.str(), ss_normal.str() );
   }  

  bar2.setMin( 1.0 );
  bar2.setMax ( 10.0 );
  bar2.setStyle( "loader", "#" );

  for( double i = bar2.getMin(); i < bar2.getMax(); i += 0.1 ) 
   {
    auto first_output_multi = [ &i ]( std::ostream& ){ bars.for_one( 1, osm::updater{}, i ); };
    auto first_output_normal = [ &i ]( std::ostream& ){ bar2.update( i ); };

    auto old_buffer = std::cout.rdbuf(nullptr);
    first_output_multi( ss_multi );
    first_output_normal( ss_normal );
    std::cout.rdbuf(old_buffer);

    CHECK_EQ( ss_multi.str(), ss_normal.str() );
   }  

  bar3.setMin( 1.2f );
  bar3.setMax ( 5.8f );
  bar3.setStyle( "complete", "%", "#" );

  for( float i = bar3.getMin(); i < bar3.getMax(); i += 0.1f ) 
   {
    auto first_output_multi = [ &i ]( std::ostream& ){ bars.for_one( 2, osm::updater{}, i ); };
    auto first_output_normal = [ &i ]( std::ostream& ){ bar3.update( i ); };

    auto old_buffer = std::cout.rdbuf(nullptr);
    first_output_multi( ss_multi );
    first_output_normal( ss_normal );
    std::cout.rdbuf(old_buffer);

    CHECK_EQ( ss_multi.str(), ss_normal.str() );
   }
 }