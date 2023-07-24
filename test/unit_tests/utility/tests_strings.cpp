//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/utility/strings.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <string>

TEST_CASE("Testing the strings utilities") {
    SUBCASE("Testing find_first_alpha.") {
        std::string mixed_string{"112$@!141!f1@!!165H23@&(1p"};
        CHECK_EQ(osm::find_first_alpha(mixed_string, 0), 10);
        CHECK_EQ(osm::find_first_alpha(mixed_string, 11), 18);
        CHECK_EQ(osm::find_first_alpha(mixed_string, 19), 25);
    }
}