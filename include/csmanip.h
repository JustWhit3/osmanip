#ifndef CSMANIP_H
#define CSMANIP_H

#include <string>
#include <map>
#include <utility>

namespace osm
 {
  //====================================================
  //     TYPE ALIASES DEFINITION
  //====================================================
  using string_map = std::map <std::string, std::string>;
  using string_pair_map = std::map <std::string, std::pair<std::string, std::string>>;

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
  extern std::string feat ( string_map & generic_map, std::string feat_string );
  extern std::string feat ( string_pair_map & generic_map, std::string feat_string, int feat_int );
  extern std::string reset ( std::string reset_string );
  extern std::string go_to( int x, int y );
 }
      
#endif