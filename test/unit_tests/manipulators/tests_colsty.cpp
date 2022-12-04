//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#include <include/manipulators/colsty.hpp>
#include <include/manipulators/cursor.hpp>
#ifdef _WIN32
#include <include/utility/windows.hpp>
#endif

//Extra headers
#include <doctest/doctest.h>

//STD headers
#include <string>
#include <stdexcept>

//====================================================
//     Using namespaces
//====================================================
using namespace std::literals::string_literals;

//====================================================
//     Testing "RGB" function
//====================================================
#if defined( __linux__ ) || defined( __APPLE__ )
TEST_CASE( "Testing the RGB function." )
 {            
  CHECK_EQ( osm::RGB( 1,5,2 ), "\x1b[38;2;1;5;2m" );
  CHECK_EQ( osm::RGB( 5,1,8 ), "\x1b[38;2;5;1;8m" );
 }
#endif