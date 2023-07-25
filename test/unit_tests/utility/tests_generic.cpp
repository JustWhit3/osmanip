//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/utility/generic.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD
#include <stdexcept>
#include <string>
#include <vector>

//====================================================
//     Namespaces
//====================================================
using namespace std::string_literals;

//====================================================
//     roundoff
//====================================================
TEST_CASE_TEMPLATE("Testing the roundoff function.", T, double) {
    T var = 3.34;
    T var_2 = 3.456;
    T var_3 = 345.56;

    CHECK_EQ(osm::roundoff(var, 1), 3.3);
    CHECK_EQ(osm::roundoff(var_2, 2), 3.46);
    CHECK_EQ(osm::roundoff(var_3, 1), 345.6);
    CHECK_EQ(osm::roundoff(0.0034, 3), 0.003);
}

//====================================================
//     Operator *
//====================================================
TEST_CASE("Testing the * redefinition for string multiplication by an integer.") {
    const std::string example = "a";
    CHECK_EQ(example * 3, "aaa");
}

//============================================
//     getCommandOut
//============================================
TEST_CASE("Testing the getCommandOut function.") {
    CHECK_EQ(osm::getCommandOut("echo ciao"), "ciao\n");

    std::string my_command = "echo \"asd erd ftr\"";
    std::string output = osm::getCommandOut(my_command.c_str());
    std::vector<std::string> splitted_output = osm::split_string(output, " ");
    CHECK_EQ(splitted_output.back(), "ftr\n");
}

//====================================================
//     isFloatingPoint
//====================================================
TEST_CASE_TEMPLATE("Testing the isFLoatingPoint function.", T, double, float, long double) {
    T type = 0.;
    const int integer = 2;

    CHECK(!osm::isFloatingPoint(integer));
    CHECK(osm::isFloatingPoint(type));
}

//====================================================
//     except_error_func
//====================================================
TEST_CASE("Testing the except_error_func function.") {
    std::string var = "this";
    const std::string test_string = "\033[31mfirst" + " \""s + "\033[1m" + static_cast<std::string>(var) + "\033[22m" +
                                    "\" "s + "second\033[39m" + "\n";

    CHECK_THROWS_AS(throw(osm::except_error_func("first", var, "second")), std::runtime_error);
    CHECK_THROWS_AS(throw(osm::except_error_func<std::out_of_range>("first", var, "second")), std::out_of_range);
    CHECK_THROWS_MESSAGE(throw(osm::except_error_func("first", var, "second")), test_string);
}

//====================================================
//     one
//====================================================
TEST_CASE("Testing the one function.") {
    std::vector<int> v{1, 2, 3, 4};
    std::vector<int> counter_{};

    for (const auto& element: v) {
        if (counter_.size() == 2) {
            CHECK_EQ(osm::one(element), abs(abs(counter_.front()) - abs(counter_.back())));
        }
        counter_.push_back(element);
    }
}

//====================================================
//     split_string
//====================================================
TEST_CASE("Testing the split_string function.") {
    CHECK_EQ(osm::split_string("aa bb cc", " ")[1], "bb");
    CHECK_EQ(osm::split_string("aaqfq dddd ff", " ").back(), "ff");
}

//====================================================
//     is_escape
//====================================================
TEST_CASE("Testing is_escape function.") {
    CHECK(!osm::is_escape("aaa", osm::ANSI_SEARCH::first));
    CHECK(osm::is_escape("\033[30m", osm::ANSI_SEARCH::first));
    CHECK(osm::is_escape("aaa\033[30m", osm::ANSI_SEARCH::generic));
}