//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include "../include/manipulators/printer.hpp"

//Extra headers
#include <doctest/doctest.h>

//STD headers
#include <iostream>

//====================================================
//     Testing OS_Decorator
//====================================================
TEST_CASE( "Testing the OS_Decorator class methods." )
 {
  osm::OS_Decorator deco;

  //====================================================
  //     Testing setters, resetters and getters
  //====================================================
  TEST_SUITE_BEGIN( "Testing setters, resetters and getters." );

  SUBCASE( "Testing the color methods" )
   {
    // Testing the default stream
    CHECK( deco.getColorList().empty() );
    deco.setColor( "red" );
    CHECK_EQ( deco.getColor(), "red" );
    CHECK( ! deco.getColorList().empty() );
    CHECK( deco.getColorList().find( &std::cout ) != deco.getColorList().end() );
    deco.resetColor( "color" );
    CHECK( deco.getColorList().empty() );

    // Testing another stream
    deco.setColor( "blue", std::cerr );
    CHECK_EQ( deco.getColor( std::cerr ), "blue" );
    deco.setColor( "green", std::cerr );
    CHECK( deco.getColorList()[ &std::cerr ] == "green" );
    CHECK( deco.getColorList().find( &std::cerr ) != deco.getColorList().end() );
    deco.resetColor( "color", std::cerr );

    // More complex testing
    deco.setColor( "red", std::cerr );
    deco.setColor( "bd blue", std::clog );
    CHECK_EQ( deco.getColor( std::clog ), "bd blue" );
    CHECK_EQ( deco.getColor( std::cerr ), "red" );
    CHECK( deco.getColorList().find( &std::cerr ) != deco.getColorList().end() );
    CHECK( deco.getColorList().find( &std::clog ) != deco.getColorList().end() );
    deco.resetColor( "color", std::cerr );
    deco.resetColor( "bd color", std::clog );
    CHECK( deco.getColorList().empty() );

    // Testing exceptions
    CHECK_THROWS_AS( deco.setColor( "ciccio" ), std::runtime_error );
    CHECK_THROWS_AS( deco.resetColor( "ciccio" ), std::runtime_error );
   }

  SUBCASE( "Testing the style methods" )
   {
    // Testing the default stream
    CHECK( deco.getStyleList().empty() );
    deco.setStyle( "bold" );
    CHECK_EQ( deco.getStyle(), "bold" );
    CHECK( ! deco.getStyleList().empty() );
    CHECK( deco.getStyleList().find( &std::cout ) != deco.getStyleList().end() );
    deco.resetStyle( "bd/ft" );
    CHECK( deco.getStyleList().empty() );

    // Testing another stream
    deco.setStyle( "underlined", std::cerr );
    CHECK_EQ( deco.getStyle( std::cerr ), "underlined" );
    deco.setStyle( "italics", std::cerr );
    CHECK( deco.getStyleList()[ &std::cerr ] == "italics" );
    CHECK( deco.getStyleList().find( &std::cerr ) != deco.getStyleList().end() );
    deco.resetStyle( "italics", std::cerr );

    // More complex testing
    deco.setStyle( "bold", std::cerr );
    deco.setStyle( "italics", std::clog );
    CHECK_EQ( deco.getStyle( std::clog ), "italics" );
    CHECK_EQ( deco.getStyle( std::cerr ), "bold" );
    CHECK( deco.getStyleList().find( &std::cerr ) != deco.getStyleList().end() );
    CHECK( deco.getStyleList().find( &std::clog ) != deco.getStyleList().end() );
    deco.resetStyle( "bd/ft", std::cerr );
    deco.resetStyle( "italics", std::clog );
    CHECK( deco.getStyleList().empty() );

    // Testing exceptions
    CHECK_THROWS_AS( deco.setStyle( "ciccio" ), std::runtime_error );
    CHECK_THROWS_AS( deco.resetStyle( "ciccio" ), std::runtime_error );
   }

  TEST_SUITE_END();
 }