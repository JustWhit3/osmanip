//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include <osmanip/graphics/canvas.hpp>

//Extra headers
#include <doctest/doctest.h>

//====================================================
//     Testing "Canvas" class
//====================================================
TEST_CASE( "Testing the Canvas class methods." )
 {
  osm::Canvas canvas( 5, 6 );

  //====================================================
  //     Testing getters, setters and constructor
  //====================================================
  TEST_SUITE_BEGIN( "Setters, getters and constructors." );

  SUBCASE( "Testing naked getters and constructor." ) 
   {
    CHECK_EQ( canvas.getWidth(), 5 );
    CHECK_EQ( canvas.getHeight(), 6 );
    CHECK_EQ( canvas.isFrameEnabled(), false );
    CHECK_EQ( canvas.getBackground(), ' ' );
    CHECK_EQ( canvas.getBackgroundFeat(), "" );
   }

  SUBCASE( "Testing getters and setters." ) 
   {
    static const std::string str = "str";

    canvas.setBackground( 'c', "str" );
    CHECK_EQ( canvas.getBackground(), 'c' );
    CHECK_EQ( canvas.getBackgroundFeat(), str);

    canvas.enableFrame( true );
    CHECK_EQ( canvas.isFrameEnabled(), true );

    canvas.setFrame( osm::FrameStyle::ASCII, str );
    CHECK_EQ( canvas.getFrameStyle(), osm::FrameStyle::ASCII );
    CHECK_EQ( canvas.getFrameFeat(), str );

    canvas.setWidth( 67 );
    CHECK_EQ( canvas.getWidth(), 67 );

    canvas.setHeight( 44 );
    CHECK_EQ( canvas.getHeight(), 44 );
   }

  TEST_SUITE_END();
 }