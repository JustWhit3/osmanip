#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//My headers
#include "../include/manipulators/csmanip.hpp"

//Extra headers
#include <doctest.h>

//STD headers
#include <map>
#include <vector>

using namespace std::string_literals;

//====================================================
//     GLOBAL VARIABLES DEFINITION
//====================================================
const std::string test_string = "error" + " \""s + "not"s + "\" "s + "supported" + "\n";

//====================================================
//     TESTING "feat" FUNCTIONS
//====================================================
//First overload:
TEST_CASE( "Testing the feat function." )
 {
  static std::vector <std::map <std::string, std::string>> maps_vector { osm::col, osm::sty };

  for( auto & element_v: maps_vector )
   {
    for( auto & element_m: element_v )
    {
     CHECK_EQ( osm::feat( element_v, element_m.first ), element_v.at( element_m.first ) );
    }
   }

  CHECK_THROWS_AS( osm::feat( osm::col, "not" ), std::runtime_error );
  CHECK_THROWS_MESSAGE( osm::feat( osm::col, "not" ), test_string );
  CHECK_THROWS_AS( osm::feat( osm::sty, "not" ), std::runtime_error );
  CHECK_THROWS_MESSAGE( osm::feat( osm::sty, "not" ), test_string );
 }

//Testing the "feat" function overload for the crs map:
TEST_CASE( "Testing the feat function overload for the crs map." )
 {  
  for( auto & element_m: osm::crs )
   {
    static const int feat_int = 100;

    CHECK_EQ( osm::feat( osm::crs, element_m.first, feat_int ), ( osm::crs.at( element_m.first ).first + std::to_string( feat_int ) + osm::crs.at( element_m.first ).second ) );
   }

  CHECK_THROWS_AS( osm::feat( osm::crs, "not", 32 ), std::runtime_error );
  CHECK_THROWS_MESSAGE( osm::feat( osm::crs, "not", 32 ), test_string );
 }

//====================================================
//     TESTING "reset" FUNCTION
//====================================================
TEST_CASE( "Testing the reset function." )
 {
  for( auto & element_m: osm::rst )
   {
    CHECK_EQ( osm::reset( element_m.first ), osm::rst.at( element_m.first ) );
   }

  CHECK_THROWS_AS( osm::reset( "not" ), std::runtime_error );
  CHECK_THROWS_MESSAGE( osm::reset( "not" ), test_string );
 }

//====================================================
//     TESTING "go_to" FUNCTION
//====================================================
TEST_CASE( "Testing the go_to function." )
 {           
  static const std::string test_string_goto = "\u001b[" +
                                              std::to_string( 2 ) + ";"s +
                                              std::to_string( 5 ) + "H"s;

  CHECK_EQ( osm::go_to( 2, 5 ), test_string_goto );
 }

//====================================================
//     TESTING "RGB" FUNCTION
//====================================================
TEST_CASE( "Testing the RGB function." )
 {            
  CHECK_EQ( osm::RGB( 1,5,2 ), "\x1b[38;2;1;5;2m" );
  CHECK_EQ( osm::RGB( 5,1,8 ), "\x1b[38;2;5;1;8m" );
 }