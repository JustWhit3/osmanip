//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include <utility/iostream.hpp>
#include <manipulators/decorator.hpp>

//Extra headers
#include <doctest/doctest.h>
#include <arsenalgear/stream.hpp>

//STD headers
#include <streambuf>
#include <sstream>

//====================================================
//     Testing OS_Decorator
//====================================================
TEST_CASE( "Testing the OS_Decorator class methods." )
 {
  //====================================================
  //     Testing setters, resetters and getters
  //====================================================
  TEST_SUITE_BEGIN( "Testing setters, resetters and getters." );

  osm::Decorator deco;

  SUBCASE( "Testing the color methods." )
   {
    // Testing the default stream
    CHECK( deco.getColorList().empty() );
    deco.setColor( "red" );
    CHECK_EQ( deco.getColor(), "red" );
    CHECK( ! deco.getColorList().empty() );
    CHECK( deco.getColorList().find( &osm::cout ) != deco.getColorList().end() );
    deco.resetColor();
    CHECK( deco.getColorList().empty() );

    // Testing another stream
    deco.setColor( "blue", std::cerr );
    CHECK_EQ( deco.getColor( std::cerr ), "blue" );
    deco.setColor( "green", std::cerr );
    CHECK( deco.getColorList()[ &std::cerr ] == "green" );
    CHECK( deco.getColorList().find( &std::cerr ) != deco.getColorList().end() );
    deco.resetColor( std::cerr );

    // More complex testing
    deco.setColor( "red", std::cerr );
    deco.setColor( "bd blue", std::clog );
    CHECK_EQ( deco.getColor( std::clog ), "bd blue" );
    CHECK_EQ( deco.getColor( std::cerr ), "red" );
    CHECK( deco.getColorList().find( &std::cerr ) != deco.getColorList().end() );
    CHECK( deco.getColorList().find( &std::clog ) != deco.getColorList().end() );
    deco.resetColor( std::cerr );
    deco.resetColor( std::clog );
    CHECK( deco.getColorList().empty() );

    // Testing exceptions
    deco.setColor( "ciccio" );
    CHECK_THROWS_AS( deco( osm::cout ) << "Test", std::runtime_error );
    deco.resetColor();
   }

  SUBCASE( "Testing the style methods." )
   {
    // Testing the default stream
    CHECK( deco.getStyleList().empty() );
    deco.setStyle( "bold" );
    CHECK_EQ( deco.getStyle(), "bold" );
    CHECK( ! deco.getStyleList().empty() );
    CHECK( deco.getStyleList().find( &osm::cout ) != deco.getStyleList().end() );
    deco.resetStyle();
    CHECK( deco.getStyleList().empty() );

    // Testing another stream
    deco.setStyle( "underlined", std::cerr );
    CHECK_EQ( deco.getStyle( std::cerr ), "underlined" );
    deco.setStyle( "italics underlined", std::cerr );
    CHECK( deco.getStyleList()[ &std::cerr ] == "italics underlined" );
    CHECK( deco.getStyleList().find( &std::cerr ) != deco.getStyleList().end() );
    deco.removeStyle( "italics", std::cerr );
    CHECK( deco.getStyleList()[ &std::cerr ] == "underlined" );
    deco.setStyle( "italics underlined", std::cerr );
    deco.removeStyle( "underlined", std::cerr );
    CHECK( deco.getStyleList()[ &std::cerr ] == "italics" );
    deco.resetStyle( std::cerr );

    // More complex testing
    deco.setStyle( "bold", std::cerr );
    deco.setStyle( "italics", std::clog );
    CHECK_EQ( deco.getStyle( std::clog ), "italics" );
    CHECK_EQ( deco.getStyle( std::cerr ), "bold" );
    CHECK( deco.getStyleList().find( &std::cerr ) != deco.getStyleList().end() );
    CHECK( deco.getStyleList().find( &std::clog ) != deco.getStyleList().end() );
    deco.resetStyle( std::cerr );
    deco.resetStyle( std::clog );
    CHECK( deco.getStyleList().empty() );

    // Testing exceptions
    deco.setStyle( "ciccio" );
    CHECK_THROWS_AS( deco( osm::cout ) << "Test", std::runtime_error );
    deco.resetStyle();
   }

  TEST_SUITE_END();

  //====================================================
  //     Testing the operators overload
  //====================================================
  TEST_SUITE_BEGIN( "Testing the operators overload." );

  osm::Decorator my_shell;

  SUBCASE( "Testing the operator () overload" )
   {
    my_shell( osm::cout );
    CHECK_EQ( &my_shell.getCurrentStream(), &osm::cout );

    my_shell( std::cerr );
    CHECK_EQ( &my_shell.getCurrentStream(), &std::cerr );

    my_shell( std::clog );
    CHECK_EQ( &my_shell.getCurrentStream(), &std::clog );
   }

  SUBCASE( "Testing the operator << overload." )
   {
    std::stringstream buffer;
    my_shell.setColor( "red", buffer );
    my_shell.setStyle( "bold", buffer );

    my_shell( buffer ) << "Test";
    CHECK_EQ( buffer.str(), "\033[31m\033[1mTest\033[0m" );
    buffer.str( "" );
    buffer.clear();

    my_shell.resetColor( buffer );
    my_shell( buffer ) << "Test";
    CHECK_EQ( buffer.str(), "\033[1mTest\033[0m" );
    buffer.str( "" );
    buffer.clear();

    my_shell.resetStyle( buffer );
    my_shell( buffer ) << "Test";
    CHECK_EQ( buffer.str(), "Test\033[0m" );
    buffer.str( "" );
    buffer.clear();
   }

  TEST_SUITE_END();
 }