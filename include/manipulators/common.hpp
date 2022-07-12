//====================================================
//     Preprocessor settings
//====================================================
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