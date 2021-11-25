#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <map>
#include <vector>
#include <thread>
#include <chrono>
#include <set>
#include "../include/osmanip.h"

using namespace osm;
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//Testing the "feat" function:
TEST_CASE( "Testing the feat function." )
 {
  vector <map <string, string>> maps_vector;
  maps_vector.push_back( col );
  maps_vector.push_back( sty );

  for( auto & element_v: maps_vector )
   {
    for( auto & element_m: element_v )
    {
     CHECK( feat( element_v, element_m.first ) == element_v.at( element_m.first ) );
    }
   }
  CHECK_THROWS_AS( feat( col, "not" ), runtime_error );
 }

//Testing the "feat" function overload for the crs map:
TEST_CASE( "Testing the feat function overload for the crs map." )
 {
  int feat_int = 100;
  for( auto & element_m: crs )
   {
    CHECK( feat( crs, element_m.first, feat_int ) == ( crs.at( element_m.first ).first + std::to_string( feat_int ) + crs.at( element_m.first ).second ) );
   }
  CHECK_THROWS_AS( feat( crs, "not", 32 ), runtime_error );
 }

//Testing the "reset" function:
TEST_CASE( "Testing the reset function." )
 {
  for( auto & element_m: rst )
   {
    CHECK( reset( element_m.first ) == rst.at( element_m.first ) );
   }
  CHECK_THROWS_AS( reset ( "not" ), runtime_error );
 }

//Testing the ProgressBar class methods:
TEST_CASE( "Testing the ProgressBar class methods." )
 {
  ProgressBar bar; 
  long long int max = 1e15,
                min = -1e15,
                time = 1e10;
  string style = "%",
         message = "message",
         bracket_open = "{",
         bracket_close = "}",
         color = "red",
         type = "indicator";

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
    //CHECK_THROWS_AS( bar.setStyle( "a", style ), runtime_error ); //Need to fix this.
   }

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
    //CHECK_THROWS_AS( bar.addStyle( "indicatorr", "%" ), runtime_error ); //Need to fix this.
   }
 }

//Testing the helper functions:
TEST_CASE( "Testing the helper function." )
 {
  SUBCASE( "Testing the * redefinition for string multiplication by an integer" )
   {
    std::string example = "a";
    CHECK( example * 3 == "aaa" );
    CHECK( 3 * example == "aaa" );
   }

  SUBCASE( "Testing the elem_in_map function" )
   {
    std::string color = "red";
    std::string color_null = "null";
    std::string indicator = "indicator";

    string_set_map styles_map_
     {
      { "indicator", { "%", "/100" } },
      { "loader", { "#" } },
     };

    CHECK( elem_in_map( color, col ) );
    CHECK( !elem_in_map( color_null, col ) );
    CHECK( elem_in_map( indicator, styles_map_ ) );
   }
 }