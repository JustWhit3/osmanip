//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/manipulators/cursor.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <stdexcept>
#include <string>

//====================================================
//     Using namespaces
//====================================================
using namespace std::literals::string_literals;

//====================================================
//     Testing "feat" function (second overload)
//====================================================
TEST_CASE("Testing the feat function overload for the crs map.") {
    const std::string test_string =
        "error" + " \""s + "not"s + "\" "s + "supported" + "\n";

    for (auto& element_m : osm::crs) {
        static const int32_t feat_int{100};

        CHECK_EQ(
            osm::feat(osm::crs, element_m.first, feat_int),
            (osm::crs.at(element_m.first).first + std::to_string(feat_int) +
             osm::crs.at(element_m.first).second));
    }

    CHECK_THROWS_AS(osm::feat(osm::crs, "not", 32), std::runtime_error);
    CHECK_THROWS_MESSAGE(osm::feat(osm::crs, "not", 32), test_string);
}

//====================================================
//     Testing "go_to" function
//====================================================
TEST_CASE("Testing the go_to function.") {
    static const std::string test_string_goto =
        "\u001b[" + std::to_string(2) + ";"s + std::to_string(5) + "H"s;

    CHECK_EQ(osm::go_to(2, 5), test_string_goto);
}