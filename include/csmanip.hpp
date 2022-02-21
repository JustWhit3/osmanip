#ifndef CSMANIP_HPP
#define CSMANIP_HPP

#include <string>
#include <map>

#include "aliases.hpp"

namespace osm
 {
  //====================================================
  //     ENUM CLASSES
  //====================================================
  enum class CURSOR { ON, OFF };

  //====================================================
  //     VARIABLES DECLARATION
  //====================================================
  extern std::map <std::string, std::string> col, sty, rst, tcs;
  extern string_pair_map crs, tcsc;

  //====================================================
  //     FUNCTIONS DECLARATION
  //====================================================
  extern std::string feat( std::map <std::string, std::string> & generic_map, std::string feat_string );
  extern std::string feat( string_pair_map & generic_map, std::string feat_string, int feat_int );
  extern std::string reset( std::string reset_string );
  extern std::string go_to( int x, int y );
  extern std::string RGB( int r, int g, int b );

  //====================================================
  //     TEMPLATE FUNCTIONS DECLARATION
  //====================================================
  template <typename T>
  extern void OPTION( const T opt );
 }
      
#endif