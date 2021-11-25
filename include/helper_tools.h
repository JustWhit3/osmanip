#ifndef HELPER_TOOLS_H
#define HELPER_TOOLS_H

#include <string>
#include <map>

namespace osm
 {
  //Operators redefinition:
  extern std::string operator * ( const std::string & generic_string, unsigned int integer );
  extern std::string operator * ( unsigned int integer, const std::string & generic_string );

  //Template functions definition:
  template <typename T>
  extern std::runtime_error runtime_error_func( std::string beg, T variable, std::string end );

  template <typename T, typename M>
  extern bool elem_in_map( T elem, std::map <T, M> map_);
 }
#endif