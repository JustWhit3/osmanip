#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include "../include/osmanip.hpp"

using namespace osm;

//====================================================
//     GLOBAL VARIABLES DEFINITION
//====================================================
ProgressBar <int> bar1;
ProgressBar <double> bar2;
ProgressBar <float> bar3;
auto bars = MultiProgressBar( bar1, bar2, bar3 );

//====================================================
//     TESTING "size" METHOD
//====================================================
TEST_CASE( "Testing the size method" )
 {
  CHECK_EQ( bars.size(), 3 );
 }

//====================================================
//     TESTING "MultiProgressBar" FUNCTION
//====================================================
TEST_CASE( "Testing the MultiProgressBar function" )
 {

 }

//====================================================
//     TESTING "operator()" REDEFINITION IN UPDATER
//====================================================
TEST_CASE( "Testing the operator() redefinition in the updater struct" )
 {
  bar1.setMin( 0 );
  bar1.setMax ( 60 );
  for( int i = bar1.getMin(); i < bar1.getMax(); i++ ) 
   {
    //bars.for_one( 0, updater{}, i ), bar1.update( i );
   }  

  bar2.setMin( 1.0 );
  bar2.setMax ( 10.0 );
  for( double i = bar2.getMin(); i < bar2.getMax(); i += 0.1) 
   {
    //bars.for_one( 1, updater{}, i );
   }  

  bar3.setMin( 1.2f );
  bar3.setMax ( 5.8f );
  for( float i = bar3.getMin(); i < bar3.getMax(); i += 0.1f ) 
   {
    //bars.for_one( 2, updater{}, i );
   }
 }