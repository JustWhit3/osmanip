//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include "../../../include/utility/strings.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <string>

TEST_CASE( "Testing the strings utilities" )
 {
  SUBCASE( "Testing find_first_alpha." )
   {
    std::string mixed_string = "112$@!141!f1@!!165H23@&(1p";
    CHECK_EQ( osm::find_first_alpha( 0, mixed_string ), 10 );
    CHECK_EQ( osm::find_first_alpha( 11, mixed_string ), 18 );
    CHECK_EQ( osm::find_first_alpha( 19, mixed_string ), 25 );
   }

  SUBCASE( "Testing get_formatted_string." )
   {
    std::string csi_string = "\u001b[2TThis \u001b[1Sis\u001b[0K a \u001b[33mstring";
    std::string formatted_string = osm::get_formatted_string( csi_string );
    std::string normal_string = "This is a string";
    CHECK_NE( formatted_string, csi_string );
    CHECK_EQ( formatted_string, normal_string );
   }

  SUBCASE( "Testing erase_last_line." )
   {
    std::string lorem_ipsum_str;
    std::string modified_str;

    lorem_ipsum_str = "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt "
                      "ut labore et dolore magna aliqua. Fermentum et sollicitudin ac orci phasellus. Ut tortor "
                      "pretium viverra suspendisse. Nunc aliquet bibendum enim facilisis gravida neque convallis "
                      "a cras.\nPellentesque dignissim enim sit amet venenatis urna. At lectus urna duis convallis.";

    modified_str = osm::erase_last_line( lorem_ipsum_str );

    CHECK_NE( lorem_ipsum_str, modified_str );

    lorem_ipsum_str = "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt "
                      "ut labore et dolore magna aliqua. Fermentum et sollicitudin ac orci phasellus. Ut tortor "
                      "pretium viverra suspendisse. Nunc aliquet bibendum enim facilisis gravida neque convallis "
                      "a cras.\n";

    CHECK_EQ( lorem_ipsum_str, modified_str );

    // Nothing is erased
    modified_str = osm::erase_last_line( lorem_ipsum_str );
    CHECK_EQ( lorem_ipsum_str, modified_str );

    // Erase '\n'
    lorem_ipsum_str.erase( lorem_ipsum_str.size() - 1 );
    modified_str = osm::erase_last_line( lorem_ipsum_str );
    CHECK_NE( lorem_ipsum_str, modified_str );

    lorem_ipsum_str = "Lorem ipsum dolor sit amet, consectetur adipiscing\n";
    CHECK_EQ( lorem_ipsum_str, modified_str );

    // Again, erase '\n'
    lorem_ipsum_str.erase( lorem_ipsum_str.size() - 1 );
    modified_str = osm::erase_last_line( lorem_ipsum_str );

    // '\n' not met, so string does not change.
    CHECK_EQ( lorem_ipsum_str, modified_str );
   }
 }