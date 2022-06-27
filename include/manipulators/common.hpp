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
#include <map>

namespace osm
 {  
  //====================================================
  //     Functions
  //====================================================
  extern std::string feat( const std::map <std::string, std::string>& generic_map, const std::string& feat_string );
 }

#endif