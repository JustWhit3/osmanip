//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include "../include/graphics/plot_2D.hpp"
#ifdef _WIN32
#include "../include/utility/windows.hpp"
#endif

//Extra headers
#include <doctest/doctest.h>

#ifdef _WIN32
void __attribute__((constructor)) osm::enableANSI();
#endif

//====================================================
//     Testing "Plot2DCanvas" class
//====================================================
TEST_CASE( "Testing the Canvas class methods." )
 {
  osm::Plot2DCanvas cv( 5,7 );

  //====================================================
  //     Testing getters, setters and constructor
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
 
#ifdef _WIN32
void __attribute__((constructor)) osm::disableANSI();
#endif