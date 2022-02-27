#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//My headers
#include "../include/osmanip.hpp"

//Extra headers
#include <doctest.h>

//Using namespaces
using namespace std;
using namespace osm;

//====================================================
//     GBLOBAL VARIABLES DEFINITION
//====================================================


//====================================================
//     TESTING "Canvas" CLASS METHODS
//====================================================
TEST_CASE( "Testing the Canvas class methods." )
 {
  Plot2DCanvas cv( 5,7 );

  //====================================================
  //     TESTING GETTERS, SETTERS AND CONSTRUCTORS
  //====================================================
  TEST_SUITE_BEGIN( "Setters, getters and constructors." );

  SUBCASE( "Testing naked getters and constructor." ) 
   {
    CHECK_EQ( cv.getOffsetX(), 0 );
    CHECK_EQ( cv.getOffsetY(), 0 );
    CHECK_EQ( cv.getScaleX(), 1 );
    CHECK_EQ( cv.getScaleY(), 1 );
   }

  SUBCASE( "Testing getters and setters." ) 
   {
    cv.setOffset( 2, 3 );
    CHECK_EQ( cv.getOffsetX(), 2 );
    CHECK_EQ( cv.getOffsetY(), 3 );

    cv.setScale( 1, 10 );
    CHECK_EQ( cv.getScaleX(), 1 );
    CHECK_EQ( cv.getScaleY(), 10 );
   }

  TEST_SUITE_END();
 }