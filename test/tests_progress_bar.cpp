#include <doctest.h>
#include <vector>
#include <thread>
#include <chrono>
#include "../include/osmanip.h"

using namespace osm;
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//====================================================
//     TESTING "ProgressBar" class METHODS
//====================================================
TEST_CASE( "Testing the ProgressBar class methods." )
 {
  ProgressBar <long long> bar; 
  long long int max = 1e15,
                min = -1e15,
                time = 1e10;
  string style = "%",
         message = "message",
         bracket_open = "{",
         bracket_close = "}",
         color = "red",
         type = "indicator";

  //====================================================
  //     TESTING GETTERS, SETTERS AND CONSTRUCTORS
  //====================================================
  SUBCASE( "Testing naked getters and constructor" ) 
   {
    CHECK( bar.getMax() == 0 );
    CHECK( bar.getMin() == 0 );
    CHECK( bar.getStyle() == "" );
    CHECK( bar.getType() == "" );
    CHECK( bar.getTime() == 0 );
    CHECK( bar.getMessage() == "" );
    CHECK( bar.getBrackets_close() == "" );
    CHECK( bar.getBrackets_open() == "" );
    CHECK( bar.getColor() == reset( "color" ));
   }

  bar.setMax( max );
  bar.setMin( min );
  bar.setStyle( type, style );
  bar.setMessage( message );
  bar.setBrackets( bracket_open, bracket_close );
  bar.setColor( color );

  SUBCASE( "Testing setters and getters with values different from 0" ) 
   {
    CHECK( bar.getMax() == max );
    CHECK( bar.getMin() == min );
    CHECK( bar.getMessage() == message );
    CHECK( bar.getBrackets_open() == bracket_open );
    CHECK( bar.getBrackets_close() == bracket_close );
    CHECK( bar.getColor() == feat( col, "red" ) );
    CHECK( bar.getStyle() == style );
    CHECK( bar.getType() == type );

    CHECK_THROWS_AS( bar.setStyle( type, "a" ), runtime_error );
    CHECK_THROWS_AS( bar.setStyle( "a", style ), runtime_error );

    //Extra test for getStyle:
    string style_p_ = "%",
           style_l_ = "#",
           complete_style = "Percentage: \"" + style_p_ + "\"\n" + "Loader: \"" + style_l_ + "\"\n"; 

    bar.setStyle( "complete", style_p_, style_l_ );
    CHECK( bar.getStyleComplete() == complete_style );
    bar.setStyle( type, style );
   }

  //====================================================
  //     TESTING RESETTERS
  //====================================================
  SUBCASE( "Testing reset method" ) 
   {
    bar.resetAll();
    CHECK( bar.getMax() == 0 );
    CHECK( bar.getMin() == 0 );
    CHECK( bar.getStyle() == "" );
    CHECK( bar.getType() == "" );
    CHECK( bar.getTime() == 0 );
    CHECK( bar.getMessage() == "" );
    CHECK( bar.getColor() == reset( "color" ) );
   }

  SUBCASE( "Testing each single reset method" ) 
   {
    bar.resetMax();
    CHECK( bar.getMax() == 0 );
    bar.resetMin();
    CHECK( bar.getMin() == 0 );
    bar.resetStyle();
    CHECK( bar.getStyle() == "" );
    CHECK( bar.getType() == "" );
    bar.resetTime();
    CHECK( bar.getTime() == 0 );
    bar.resetMessage();
    CHECK( bar.getMessage() == "" );
    bar.resetBrackets();
    CHECK( bar.getBrackets_open() == "" );
    CHECK( bar.getBrackets_close() == "" );
    bar.resetColor();
    CHECK( bar.getColor() == reset( "color" ) );
   }

  //====================================================
  //     TESTING THE "time" METHODS
  //====================================================
  SUBCASE( "Testing time methods" )
   {
    bar.setBegin();
     for ( int i = 0; i < 5; i++ )
      {
       sleep_for( milliseconds( 100 ) );
      }
    bar.setEnd();
    CHECK( bar.getTime() == 500 );

    bar.resetTime();
    CHECK( bar.getTime() == 0 );
   }

  //====================================================
  //     TESTING THE "update" METHOD
  //====================================================
  SUBCASE( "Testing update method" )
   {
    bar.setMax( 5 );
    bar.setMin( -3 );
    bar.resetStyle();
    bar.setStyle( type, "%" );

    //There is not much to test in it since it doesn't modify almost anything.
    for ( int i = -3; i < 5; i++ )
     {
      bar.update( i );
      CHECK( bar.getIteratingVar() == 100 * ( i - bar.getMin() ) / ( bar.getMax() - bar.getMin() - 1 ) + 1 );
     }
   }

  //====================================================
  //     TESTING THE "addStyle" METHOD
  //====================================================
  SUBCASE( "Testing addStyle method" )
   {
    bar.addStyle( "indicator", "|100" );
    bar.setStyle( "indicator", "|100" );
    CHECK( bar.getStyle() == "|100" );
    bar.addStyle( "loader", ">" );
    bar.setStyle( "complete", "|100", ">" );
    CHECK( bar.getStyle() == "|100>" );
    CHECK_THROWS_AS( bar.addStyle( "indicator", "%" ), runtime_error );
    CHECK_THROWS_AS( bar.addStyle( "loader", "#" ), runtime_error );
    CHECK_THROWS_AS( bar.addStyle( "indicatorr", "%" ), out_of_range );
   }

  //====================================================
  //     TESTING THE "one" METHOD
  //====================================================
  SUBCASE( "Testing the one method" )
   {
    std::vector <int> v = { 1, 2, 3, 4 }, counter_ ( 2 );
    ProgressBar <int> progress;
    for( const auto & element: v )
     {
      if( counter_.size() == 2 )
       {
        progress.one( element ) == abs( abs( counter_.front() ) - abs( counter_.back() ) );
       }
      progress.one( element ) == 0;
     }
    CHECK( counter_.size() == 2 );
   }
 }