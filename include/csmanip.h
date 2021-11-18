#ifndef CSMANIP_H
#define CSMANIP_H

#include <string>
#include <map>

namespace osm
 {
  //Maps declaration:
  extern std::map <std::string, std::string> col, sty, rst, crs;

  //Functions declaration:
  std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat_string );
  std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat_string, int feat_int );
  std::string reset ( std::string reset_string );

  //Test functions declaration:
  void feat_test( std::map <std::string, std::string> & generic_map_test );
  void reset_test();
 }
      
#endif