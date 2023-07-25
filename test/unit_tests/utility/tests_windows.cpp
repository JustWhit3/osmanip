//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#ifdef _WIN32
#include <osmanip/utility/windows.hpp>
#endif

// Extra headers
#include <doctest/doctest.h>

#include <arsenalgear/system.hpp>
#include <arsenalgear/utils.hpp>

// STD headers
#include <string>

#ifdef _WIN32

TEST_CASE("Testing the enableUNICODE and disableUNICODE functions.") {
    const std::string old_chcp_pre = agr::getCommandOut("chcp");
    std::string old_chcp = agr::split_string(old_chcp_pre, " ").back();

    osm::enableUNICODE();
    const std::string old_chcp_pre_UNICODE = agr::getCommandOut("chcp");
    std::string old_chcp_UNICODE = agr::split_string(old_chcp_pre_UNICODE, " ").back();

    CHECK_EQ(old_chcp_UNICODE, "65001\n");

    osm::disableUNICODE();
    const std::string old_chcp_pre_UNICODE_off = agr::getCommandOut("chcp");
    std::string old_chcp_UNICODE_off = agr::split_string(old_chcp_pre_UNICODE_off, " ").back();

    CHECK_EQ(old_chcp_UNICODE_off, old_chcp);
}

#endif