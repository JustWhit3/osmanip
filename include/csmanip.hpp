#ifndef CSMANIP_HPP
#define CSMANIP_HPP

#include <iostream>
#include <string>
#include <map>

#include "aliases.hpp"
#include "helper_tools.hpp"

namespace osm
 {
  //====================================================
  //     ENUM CLASSES
  //====================================================
  enum class CURSOR { ON, OFF };

  //====================================================
  //     VARIABLES DECLARATION
  //====================================================
  extern const std::map <std::string, std::string> col, sty, rst, tcs;
  extern const string_pair_map crs, tcsc;

  //====================================================
  //     FUNCTIONS DECLARATION
  //====================================================
  extern std::string feat( const std::map <std::string, std::string>& generic_map, const std::string& feat_string );
  extern std::string feat( const string_pair_map& generic_map, const std::string& feat_string, const int& feat_int );
  extern std::string reset( const std::string& reset_string );
  extern std::string go_to( const int& x, const int& y );
  extern std::string RGB( const int& r, const int& g, const int& b );

  //====================================================
  //     TEMPLATE FUNCTIONS DECLARATION
  //====================================================
  template <typename T>
  extern void OPTION( const T& opt );

  //====================================================
  //     TEMPLATE "printf" FUNCTIONS DEFINITION
  //====================================================
  namespace print
   {
    template <typename... Args>
    inline void printf( std::ostream& os = null_stream, const Args&... args )
     {
      if( &os == &null_stream ) std::cout << "\n";
      else if( &os == &std::cerr ) os << feat( col, "red" ) << feat( sty, "bold" );
      else if( &os == &std::clog ) os << feat( col, "lt blue" ) << feat( sty, "bold" );
  
      ( os << ... << args ) << "\n";
  
      if( &os == &std::cerr || &os == &std::clog || &os == &std::cout ) os << reset( "all" );
     }

    template <typename... Args>
    inline void printf( Args&... args )
     {
      ( std::cout << ... << args ) << "\n" << reset( "all" );
     }
   }
 }

#endif