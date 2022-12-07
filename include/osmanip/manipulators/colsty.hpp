//====================================================
//     File data
//====================================================
/**
 * @file colsty.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_COLSTY_HPP
#define OSMANIP_COLSTY_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <string>
#include <unordered_map>
#include <stdint.h>

namespace osm
 {
  //====================================================
  //     Variables
  //====================================================
  extern const std::unordered_map <std::string, std::string> col, sty, rst;

  //====================================================
  //     Functions
  //====================================================
  extern const std::string RGB( int32_t r, int32_t g, int32_t b );
 }

#endif