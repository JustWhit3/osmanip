#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include <map>
#include <vector>
#include "../include/osmanip.h"

using namespace osm;
using namespace std;

//====================================================
//     GLOBAL MACROS DEFINITION
//====================================================
#define test_string "error" +                                      \
                     static_cast <std::string>(" \"") +            \
                     static_cast <std::string>( "not" ) +          \
                     static_cast <std::string>( "\" " ) +          \
                     "supported" +                                 \
                     "\n"                                          \

#define test_string_goto "\u001b[" +                               \
                            std::to_string( 2 ) +                  \
                            static_cast <std::string>( ";" ) +     \
                            std::to_string( 5 ) +                  \
                            static_cast <std::string>( "H" )       \

#define maps_vector vector <map <string, string>> { col, sty }     \

#define feat_int 100                                               \

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
//     TESTING "go_to" FUNCTIONS
//====================================================
TEST_CASE( "Testing the reset function." )
 {            
  CHECK_EQ( go_to( 2, 5 ), test_string_goto );
 }