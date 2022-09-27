//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef COLSTY_HPP
#define COLSTY_HPP

//====================================================
//     Headers
//====================================================

//My headers
#include "common.hpp"

//STD headers
#include <string>
#include <unordered_map>

namespace osm
 {
  //====================================================
  //     Variables
  //====================================================
  extern const std::unordered_map <std::string, std::string> col, sty, rst;

  //====================================================
  //     Functions
  //====================================================
  extern const std::string RGB( const int& r, const int& g, const int& b );
 }

#endif