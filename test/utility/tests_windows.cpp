//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

//My headers
#ifdef _WIN32
#include "../include/utility/windows.hpp"
#endif

//Extra headers
#include <doctest/doctest.h>
#include <arsenalgear/system.hpp>
#include <arsenalgear/utils.hpp>

//STD headers
#include <string>

#ifdef _WIN32

TEST_CASE( "Testing the " )
 {
  const std::string old_chcp_pre = agr::getCommandOut( "chcp" );
  std::string old_chcp = agr::split_string( old_chcp_pre, " " ).back();

  osm::enableUNICODE();
  CHECK_EQ( agr::getCommandOut( "chcp" ), 65001 );

  osm::disableUNICODE();
  CHECK_EQ( agr::getCommandOut( "chcp" ), old_chcp_pre );
 }

#endif