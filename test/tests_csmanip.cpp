#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <map>
#include <vector>
#include "../include/osmanip.h"

using namespace osm;
using namespace std;

//====================================================
//     TESTING "feat" FUNCTIONS
//====================================================

//First overload:
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

//====================================================
//     TESTING "reset" FUNCTION
//====================================================
TEST_CASE( "Testing the reset function." )
 {
  for( auto & element_m: rst )
   {
    CHECK( reset( element_m.first ) == rst.at( element_m.first ) );
   }
  CHECK_THROWS_AS( reset ( "not" ), runtime_error );
 }