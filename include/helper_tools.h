#ifndef HELPER_TOOLS_H
#define HELPER_TOOLS_H

#include <string>
#include <map>
#include <functional>
namespace osm
 {
  //Operators redefinition:
  extern std::string operator * ( const std::string & generic_string, unsigned int integer );
  extern std::string operator * ( unsigned int integer, const std::string & generic_string );

  //Template functions definition:
  template <typename T>
  extern std::runtime_error runtime_error_func( std::string beg, T variable, std::string end );

  template <typename T, typename R>
  extern T check_condition( std::function <bool()> condition, T return_it, R return_false );

  template <typename T>
  extern bool isFloatingPoint( const T & expression );
 }
#endif