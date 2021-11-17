#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <map>
#include <vector>
#include <thread>
#include <chrono>
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
  maps_vector.push_back( crs );

  for( auto & element_v: maps_vector )
   {
    for( auto & element_m: element_v )
    {
     if( element_v.find( element_m.first ) == col.end() )
      {
       CHECK_THROWS_AS( feat( element_v, element_m.first ), runtime_error );
      }
     else
      {
       CHECK( feat( element_v, element_m.first ) == element_v.at( element_m.first ) );
      }
    }
   }
 }

//Testing the "reset" function:
TEST_CASE( "Testing the reset function." )
 {
  for( auto & element_m: rst )
   {
   if( rst.find( element_m.first ) == rst.end() )
     {
      CHECK_THROWS_AS( reset( element_m.first ), runtime_error );
     }
   else
     {
      CHECK( reset( element_m.first ) == rst.at( element_m.first ) );
     }
   }
 }

//Testing the ProgressBar class methods:
TEST_CASE( "Testing the ProgressBar class methods." )
 {
  ProgressBar bar; 
  long long int max = 1e15,
                min = -1e15,
                time = 1e10;
  string style = "%",
         message = "meessage",
         bracket_open = "{",
         bracket_close = "}";

  SUBCASE( "Testing naked getters and constructor" ) 
   {
    CHECK( bar.getMax() == 0 );
    CHECK( bar.getMin() == 0 );
    CHECK( bar.getStyle() == "" );
    CHECK( bar.getTime() == 0 );
    CHECK( bar.getMessage() == "" );
    CHECK( bar.getBrackets_close() == "" );
    CHECK( bar.getBrackets_open() == "" );
   }

  bar.setMax( max );
  bar.setMin( min );
  bar.setStyle( style );
  bar.setMessage( message );
  bar.setBrackets( bracket_open, bracket_close );

  SUBCASE( "Testing setters and getters with values different from 0" ) 
   {
    CHECK( bar.getMax() == max );
    CHECK( bar.getMin() == min );
    CHECK( bar.getMessage() == message );
    CHECK( bar.getBrackets_open() == bracket_open );
    CHECK( bar.getBrackets_close() == bracket_close );

    if ( bar.getStyle() != "%" && bar.getStyle() != "#" )
     {
      CHECK_THROWS_AS( bar.setStyle( style ), runtime_error );
     }
    else
     {
      CHECK( bar.getStyle() == style );
     }
   }

  SUBCASE( "Testing reset method" ) 
   {
    bar.reset();
    CHECK( bar.getMax() == 0 );
    CHECK( bar.getMin() == 0 );
    CHECK( bar.getStyle() == "" );
    CHECK( bar.getTime() == 0 );
    CHECK( bar.getMessage() == "" );
   }

  SUBCASE( "Testing each single reset method" ) 
   {
    bar.resetMax();
    CHECK( bar.getMax() == 0 );
    bar.resetMin();
    CHECK( bar.getMin() == 0 );
    bar.resetStyle();
    CHECK( bar.getStyle() == "" );
    bar.resetTime();
    CHECK( bar.getTime() == 0 );
    bar.resetMessage();
    CHECK( bar.getMessage() == "" );
    bar.resetBrackets();
    CHECK( bar.getBrackets_open() == "" );
    CHECK( bar.getBrackets_close() == "" );
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
    bar.setStyle( "#" );

    //There is not much to test in it since it doesn't modify almost anything.
    for ( int i = -3; i < 5; i++ )
     {
      bar.update( i );
      CHECK( bar.getIteratingVar() == 100 * ( i - bar.getMin() ) / ( bar.getMax() - bar.getMin() - 1 ) );
     }
   }
 }