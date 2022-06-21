//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include "../include/manipulators/csmanip.hpp"
#include "../include/progressbar/progress_bar.hpp"

//Extra headers
#include <doctest/doctest.h>
#include <arsenalgear/math.hpp>
#include <arsenalgear/utils.hpp>

//STD headers
#include <vector>
#include <thread>
#include <chrono>

//====================================================
//     Global variables
//====================================================
const std::string style = "%";
const std::string message = "message";
const std::string bracket_open = "{";
const std::string bracket_close = "}";
const std::string color = "red";
const std::string style_p_ =  "%";
const std::string style_l_ = "#";

//====================================================
//     Testing ProgressBar
//====================================================
TEST_CASE_TEMPLATE( "Testing the ProgressBar class methods.", T, int, long, long long, double, long double, float )
 {
  osm::ProgressBar <T> bar; 
  T max = 10.,
    min = 5.,
    time = 34.;
  std::string type = "indicator";

  //====================================================
  //     Testing getters, setters and constructor
  //====================================================
  TEST_SUITE_BEGIN( "Setters, getters and constructors." );

  SUBCASE( "Testing naked getters and constructor." ) 
   {
    CHECK_EQ( bar.getMax(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getMin(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getStyle(), "" );
    CHECK_EQ( bar.getType(), "" );
    CHECK_EQ( bar.getTime(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getMessage(), "" );
    CHECK_EQ( bar.getBrackets_close(), "" );
    CHECK_EQ( bar.getBrackets_open(), "" );
    CHECK_EQ( bar.getColor(), osm::reset( "color" ));
    CHECK_EQ( bar.getColorName(), "" );
    CHECK_EQ( bar.getRemainingTimeFlag(), "off" );
   }

  bar.setMax( max );
  bar.setMin( min );
  bar.setStyle( type, style );
  bar.setMessage( message );
  bar.setBrackets( bracket_open, bracket_close );
  bar.setColor( color );
  bar.setRemainingTimeFlag( "on" );

  //Require values have been correctly initialized.
  REQUIRE( bar.getMax() != static_cast<T> ( NULL ) );
  REQUIRE( bar.getMin() != static_cast<T> ( NULL ) );
  REQUIRE( bar.getStyle() != "" );
  REQUIRE( bar.getType() != "" );
  REQUIRE( bar.getMessage() != "" );
  REQUIRE( bar.getBrackets_close() != "" );
  REQUIRE( bar.getBrackets_open() != "" );
  REQUIRE( bar.getColor() != osm::reset( "color" ) );  
  REQUIRE( bar.getColorName() != "" );
  REQUIRE( bar.getRemainingTimeFlag() != "off" );

  SUBCASE( "Testing setters and getters with initialized values." ) 
   {
    CHECK_EQ( bar.getMax(), max );
    CHECK_EQ( bar.getMin(), min );
    CHECK_EQ( bar.getMessage(), message );
    CHECK_EQ( bar.getBrackets_open(), bracket_open );
    CHECK_EQ( bar.getBrackets_close(), bracket_close );
    CHECK_EQ( bar.getColor(), osm::feat( osm::col, "red" ) );
    CHECK_EQ( bar.getColorName(), color );
    CHECK_EQ( bar.getStyle(), style );
    CHECK_EQ( bar.getType(), type );
    CHECK_EQ( bar.getRemainingTimeFlag(), "on" );

    CHECK_THROWS_AS( bar.setStyle( type, "a" ), std::runtime_error );
    CHECK_THROWS_AS( bar.setStyle( "a", style ), std::runtime_error );

    //Extra test for getStyle:
    bar.setStyle( "complete", style_p_, style_l_ );

    static const std::string complete_style = "Percentage: \"" + style_p_ + "\"\n" + "Loader: \"" + style_l_ + "\"\n";

    CHECK_EQ( bar.getStyleComplete(), complete_style );

    bar.setStyle( type, style );
   }

  TEST_SUITE_END();

  //====================================================
  //     Testing resetters
  //====================================================
  TEST_SUITE_BEGIN( "Resetters." );

  SUBCASE( "Testing reset method." ) 
   {
    bar.resetAll();

    CHECK_EQ( bar.getMax(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getMin(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getStyle(), "" );
    CHECK_EQ( bar.getType(), "" );
    CHECK_EQ( bar.getMessage(), "" );
    CHECK_EQ( bar.getColor(), osm::reset( "color" ) );
    CHECK_EQ( bar.getColorName(), "" );
    CHECK_EQ( bar.getRemainingTimeFlag(), "off" );
   }

  bar.setMax( max );
  bar.setMin( min );
  bar.setStyle( type, style );
  bar.setMessage( message );
  bar.setBrackets( bracket_open, bracket_close );
  bar.setColor( color );

  SUBCASE( "Testing each single reset method." ) 
   {
    bar.resetMax();
    bar.resetMin();
    bar.resetStyle();
    bar.resetMessage();
    bar.resetBrackets();
    bar.resetColor();

    CHECK_EQ( bar.getMin(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getMax(), static_cast<T> ( NULL ) );
    CHECK_EQ( bar.getStyle(), "" );
    CHECK_EQ( bar.getType(), "" );
    CHECK_EQ( bar.getMessage(), "" );
    CHECK_EQ( bar.getBrackets_open(), "" );
    CHECK_EQ( bar.getBrackets_close(), "" );
    CHECK_EQ( bar.getColor(), osm::reset( "color" ) );
    CHECK_EQ( bar.getColorName(), "" );
   }

  TEST_SUITE_END();

  TEST_SUITE_BEGIN( "Other methods." );

  //====================================================
  //     Testing "time" method
  //====================================================
  SUBCASE( "Testing time methods." )
   {
    bar.setBegin();
     for ( int i = 0; i < 5; i++ )
      {
       std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
      }
    bar.setEnd();
    
    CHECK( agr::IsInBounds( static_cast <int>( bar.getTime() ), 499, 502 ) );

    bar.resetTime();

    CHECK_EQ( bar.getTime(), static_cast<T> ( NULL ) );
   }

  //====================================================
  //     Testing "update" method
  //====================================================
  SUBCASE( "Testing update method." )
   {
    bar.setMax( 5 );
    bar.setMin( -3 );
    bar.resetStyle();
    bar.setStyle( type, "%" );

    //There is not much to test in it since it doesn't modify almost anything.
    for ( T i = bar.getMax(); i < bar.getMin(); i++ )
     {
      bar.update( i );
      CHECK_EQ( bar.getIteratingVar(), 100 * ( i - bar.getMin() ) / ( bar.getMax() - bar.getMin() - agr::one( i ) ) + 1 );
     }
   }

  //====================================================
  //     Testing "addStyle" method
  //====================================================
  SUBCASE( "Testing addStyle method." )
   {
    bar.addStyle( "indicator", "|100" );
    bar.setStyle( "indicator", "|100" );

    CHECK_EQ( bar.getStyle(), "|100" );

    bar.addStyle( "loader", ">" );
    bar.setStyle( "complete", "|100", ">" );

    CHECK_EQ( bar.getStyle(), "|100>" );
    CHECK_THROWS_AS( bar.addStyle( "indicator", "%" ), std::runtime_error );
    CHECK_THROWS_AS( bar.addStyle( "loader", "#" ), std::runtime_error );
    CHECK_THROWS_AS( bar.addStyle( "indicatorr", "%" ), std::out_of_range );
   }
   
  TEST_SUITE_END();

  //====================================================
  //     Testing the constructor overload
  //====================================================
  SUBCASE( "Testing constructor(min,max)." )
   {
    osm::ProgressBar mm_bar( 0, 20 );
    CHECK_EQ( mm_bar.getMin(), 0 );
    CHECK_EQ( mm_bar.getMax(), 20 );
   }  
 }