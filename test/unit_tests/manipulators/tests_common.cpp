//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include <include/manipulators/common.hpp>
#include <include/manipulators/colsty.hpp>
#ifdef _WIN32
#include <include/utility/windows.hpp>
#endif

//Extra headers
#include <doctest/doctest.h>

//STD headers
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

//====================================================
//     Using namespaces
//====================================================
using namespace std::literals::string_literals;

//====================================================
//     Main
//====================================================
int main( int argc, char** argv )
 {
  #ifdef _WIN32
  osm::enableANSI();
  #endif

  doctest::Context context;

  context.setOption( "abort-after", 5 ); 
  context.setOption( "order-by", "name" ); 

  context.applyCommandLine( argc, argv );

  int32_t res = context.run();

  #ifdef _WIN32
  osm::disableANSI();
  #endif

  if( context.shouldExit() )
   {
    return res;         
   } 
 }

//====================================================
//     Testing "feat" function (first overload)
//====================================================

//First overload:
TEST_CASE( "Testing the feat function." )
 {
  static std::vector <std::unordered_map <std::string, std::string>> maps_vector { osm::col, osm::sty, osm::rst };
  const std::string test_string = "error" + " \""s + "not"s + "\" "s + "supported" + "\n";

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