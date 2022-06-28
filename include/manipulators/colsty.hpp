//====================================================
//     Preprocessor settings
//====================================================
#ifndef COLSTY_HPP
#define COLSTY_HPP

//====================================================
//     Headers
//====================================================

//My headers
#include "common.hpp"

//STD headers
#include <string>
#include <map>

namespace osm
 {
  //====================================================
  //     Variables
  //====================================================
  extern const std::map <std::string, std::string> col, sty, rst;

  //====================================================
  //     Functions
  //====================================================
  extern std::string reset( const std::string& reset_string );
  extern std::string RGB( const int& r, const int& g, const int& b );
 }

#endif