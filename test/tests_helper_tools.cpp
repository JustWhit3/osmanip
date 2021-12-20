#include <doctest.h>
#include <functional>
#include "../include/osmanip.h"

using namespace osm;
using namespace std;

//====================================================
//     TESTING THE * REDEFINITION
//====================================================
TEST_CASE( "Testing the * redefinition for string multiplication by an integer" )
 {
  std::string example = "a";

  CHECK( example * 3 == "aaa" );
  CHECK( 3 * example == "aaa" );
 }

//====================================================
//     TESTING THE "check condition" FUNCTION
//====================================================
TEST_CASE( "Testing the check_condition function ")
 {
  int a = 3, b = 4;
  std::string test_string = "nice", null_str = "";

  CHECK( check_condition( [ a, b ](){ return a < b; }, test_string, null_str ) == test_string );
  CHECK( check_condition( [ a, b ](){ return a > b; }, test_string, null_str ) == null_str );
 }
  
//====================================================
//     TESTING THE "isFloatingPoint" FUNCTION
//====================================================
TEST_CASE( "Testing the isFLoatingPoint function" )
 {
  int a = 3;
  double d = 3.4;
  float f = 45.3F;
  long double ld = 4.2L;
  
  CHECK( !isFloatingPoint( a ) );
  CHECK( isFloatingPoint( d ) );
  CHECK( isFloatingPoint( f ) );
  CHECK( isFloatingPoint( ld ) );
 }