#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//My headers
#include "../include/osmanip.hpp"

//Extra headers
#include <doctest.h>

//STD headers
#include <map>
#include <vector>

//Using namespaces
using namespace osm;
using namespace std;

//====================================================
//     GLOBAL VARIABLES DEFINITION
//====================================================
const string test_string = "error" +
                           static_cast <std::string>(" \"") +
                           static_cast <std::string>( "not" ) +
                           static_cast <std::string>( "\" " ) +
                           "supported" +
                           "\n";
const string test_string_goto = "\u001b[" +
                                std::to_string( 2 ) +
                                static_cast <std::string>( ";" ) +
                                std::to_string( 5 ) +
                                static_cast <std::string>( "H" );
vector <map <string, string>> maps_vector { col, sty };
const int feat_int = 100;

//====================================================
//     TESTING "feat" FUNCTIONS
//====================================================
//First overload:
TEST_CASE( "Testing the feat function." )
 {
  for( auto & element_v: maps_vector )
   {
    for( auto & element_m: element_v )
    {
     CHECK_EQ( feat( element_v, element_m.first ), element_v.at( element_m.first ) );
    }
   }

  CHECK_THROWS_AS( feat( col, "not" ), runtime_error );
  CHECK_THROWS_MESSAGE( feat( col, "not" ), test_string );
  CHECK_THROWS_AS( feat( sty, "not" ), runtime_error );
  CHECK_THROWS_MESSAGE( feat( sty, "not" ), test_string );
 }

//Testing the "feat" function overload for the crs map:
TEST_CASE( "Testing the feat function overload for the crs map." )
 {  
  for( auto & element_m: crs )
   {
    CHECK_EQ( feat( crs, element_m.first, feat_int ), ( crs.at( element_m.first ).first + std::to_string( feat_int ) + crs.at( element_m.first ).second ) );
   }

  CHECK_THROWS_AS( feat( crs, "not", 32 ), runtime_error );
  CHECK_THROWS_MESSAGE( feat( crs, "not", 32 ), test_string );
 }

//====================================================
//     TESTING "reset" FUNCTION
//====================================================
TEST_CASE( "Testing the reset function." )
 {
  for( auto & element_m: rst )
   {
    CHECK_EQ( reset( element_m.first ), rst.at( element_m.first ) );
   }

  CHECK_THROWS_AS( reset( "not" ), runtime_error );
  CHECK_THROWS_MESSAGE( reset( "not" ), test_string );
 }

//====================================================
//     TESTING "go_to" FUNCTION
//====================================================
TEST_CASE( "Testing the go_to function." )
 {            
  CHECK_EQ( go_to( 2, 5 ), test_string_goto );
 }

//====================================================
//     TESTING "RGB" FUNCTION
//====================================================
TEST_CASE( "Testing the RGB function." )
 {            
  CHECK_EQ( RGB( 1,5,2 ), "\x1b[38;2;1;5;2m" );
  CHECK_EQ( RGB( 5,1,8 ), "\x1b[38;2;5;1;8m" );
 }