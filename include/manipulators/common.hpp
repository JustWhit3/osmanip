//====================================================
//     File data
//====================================================
/**
 * @file common.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef COMMON_HPP
#define COMMON_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <string>
#include <unordered_map>

namespace osm
 {  
  //====================================================
  //     Functions
  //====================================================
  extern const std::string& feat( const std::unordered_map <std::string, std::string>& generic_map, const std::string& feat_string );
 }

#endif