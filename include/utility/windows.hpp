//====================================================
//     Preprocessor settings
//====================================================
#ifndef WINDOWS_HPP
#define WINDOWS_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <string>

namespace osm
 {
  //====================================================
  //     Variables
  //====================================================
  extern std::string old_chcp;

  //====================================================
  //     Functions
  //====================================================
  extern void enableANSI();
  extern void disableANSI();
  extern void enableUNICODE();
  extern void disableUNICODE();
 }

#endif