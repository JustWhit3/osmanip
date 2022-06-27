//====================================================
//     Preprocessor settings
//====================================================
#ifndef CURSOR_HPP
#define CURSOR_HPP

//====================================================
//     Headers
//====================================================

//My headers
#include "common.hpp"

//STD headers
#include <string>
#include <map>
#include <set>

namespace osm
 {
  //====================================================
  //     Aliases
  //====================================================
  using string_pair_map = std::map <std::string, std::pair<std::string, std::string>>;

  //====================================================
  //     Variables
  //====================================================
  extern const std::map <std::string, std::string> tcs;
  extern const string_pair_map crs, tcsc;

  //====================================================
  //     Functions
  //====================================================
  extern std::string feat( const string_pair_map& generic_map, const std::string& feat_string, const int& feat_int );
  extern std::string go_to( const int& x, const int& y );
 }

#endif