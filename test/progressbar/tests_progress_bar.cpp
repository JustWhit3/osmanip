#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//My headers
#include "../include/manipulators/csmanip.hpp"
#include "../include/progressbar/progress_bar.hpp"
#include "../include/utils/helper_tools.hpp"

//Extra headers
#include <doctest.h>

//STD headers
#include <vector>
#include <thread>
#include <chrono>

//Using namespaces
using namespace osm;
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//====================================================
//     GLOBAL VARIABLES DEFINITION
//====================================================
const string style = "%";
const string message = "message";
const string bracket_open = "{";
const string bracket_close = "}";
const string color = "red";
const string style_p_ =  "%";
const string style_l_ = "#";
const string complete_style = "Percentage: \"" +
                              style_p_ +
                              "\"\n" +
                              "Loader: \"" +
                              style_l_ +
                              "\"\n";
vector <int> counter_ {};
vector <int> v { 1, 2, 3, 4 };

//====================================================
//     TESTING "ProgressBar" CLASS METHODS
//====================================================
TEST_CASE_TEMPLATE( "Testing the ProgressBar class methods.", T, int, long, long long, double, long double, float )
 {
  ProgressBar <T> bar; 
  T max = 10.,
    min = 5.,
    time = 34.;
  string type = "indicator";

  //====================================================
  //     TESTING GETTERS, SETTERS AND CONSTRUCTORS
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
    CHECK_EQ( bar.getColor(), reset( "color" ));
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
  REQUIRE( bar.getColor() != reset( "color" ) );  
  REQUIRE( bar.getRemainingTimeFlag() != "off" );

  SUBCASE( "Testing setters and getters with initialized values." ) 
   {
    CHECK_EQ( bar.getMax(), max );
    CHECK_EQ( bar.getMin(), min );
    CHECK_EQ( bar.getMessage(), message );
    CHECK_EQ( bar.getBrackets_open(), bracket_open );
    CHECK_EQ( bar.getBrackets_close(), bracket_close );
    CHECK_EQ( bar.getColor(), feat( col, "red" ) );
    CHECK_EQ( bar.getStyle(), style );
    CHECK_EQ( bar.getType(), type );
    CHECK_EQ( bar.getRemainingTimeFlag(), "on" );

    CHECK_THROWS_AS( bar.setStyle( type, "a" ), runtime_error );
    CHECK_THROWS_AS( bar.setStyle( "a", style ), runtime_error );

    //Extra test for getStyle:
    bar.setStyle( "complete", style_p_, style_l_ );

    CHECK_EQ( bar.getStyleComplete(), complete_style );

    bar.setStyle( type, style );
   }

  TEST_SUITE_END();

  //====================================================
  //     TESTING RESETTERS
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
    CHECK_EQ( bar.getColor(), reset( "color" ) );
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
    CHECK_EQ( bar.getColor(), reset( "color" ) );
   }

  TEST_SUITE_END();

  TEST_SUITE_BEGIN( "Other methods." );

  //====================================================
  //     TESTING THE "time" METHODS
  //====================================================
  SUBCASE( "Testing time methods." )
   {
    bar.setBegin();
     for ( int i = 0; i < 5; i++ )
      {
       sleep_for( milliseconds( 100 ) );
      }
    bar.setEnd();
    
    CHECK( IsInBounds( static_cast <int>( bar.getTime() ), 499, 502 ) );

    bar.resetTime();

    CHECK_EQ( bar.getTime(), static_cast<T> ( NULL ) );
   }

  //====================================================
  //     TESTING THE "update" METHOD
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
      CHECK_EQ( bar.getIteratingVar(), 100 * ( i - bar.getMin() ) / ( bar.getMax() - bar.getMin() - bar.one( i ) ) + 1 );
     }
   }

  //====================================================
  //     TESTING THE "addStyle" METHOD
  //====================================================
  SUBCASE( "Testing addStyle method." )
   {
    bar.addStyle( "indicator", "|100" );
    bar.setStyle( "indicator", "|100" );

    CHECK_EQ( bar.getStyle(), "|100" );

    bar.addStyle( "loader", ">" );
    bar.setStyle( "complete", "|100", ">" );

    CHECK_EQ( bar.getStyle(), "|100>" );
    CHECK_THROWS_AS( bar.addStyle( "indicator", "%" ), runtime_error );
    CHECK_THROWS_AS( bar.addStyle( "loader", "#" ), runtime_error );
    CHECK_THROWS_AS( bar.addStyle( "indicatorr", "%" ), out_of_range );
   }

  //====================================================
  //     TESTING THE "one" METHOD
  //====================================================
  SUBCASE( "Testing the one method." )
   {
    ProgressBar <T> progress;

    for( const auto & element: v )
     {
      if( counter_.size() == 2 )
       {
        CHECK_EQ( progress.one( element ), abs( abs( counter_.front() ) - abs( counter_.back() ) ) );
       }
      counter_.push_back( element );
     }
   }
   
  TEST_SUITE_END();
 }