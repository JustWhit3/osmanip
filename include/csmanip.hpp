#ifndef CSMANIP_HPP
#define CSMANIP_HPP

#include <string>
#include <map>

#include "aliases.hpp"

namespace osm
 {
  //====================================================
  //     VARIABLES DECLARATION
  //====================================================
  extern string_map col,
                    sty,
                    rst,
                    tcs;
  extern string_pair_map crs;

  //====================================================
  //     FUNCTIONS DECLARATION
  //====================================================
  extern std::string feat( string_map & generic_map, std::string feat_string );
  extern std::string feat( string_pair_map & generic_map, std::string feat_string, int feat_int );
  extern std::string reset( std::string reset_string );
  extern std::string go_to( int x, int y );
  extern std::string RGB( int r, int g, int b );
  extern void SET_CURSOR_VIEW( const std::string onof );
 }
      
#endif