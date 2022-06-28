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

//Extra headers
#include <arsenalgear/stream.hpp>

//STD headers
#include <iostream>
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

  //====================================================
  //     print (first overload)
  //====================================================
  /**
   * @brief It can be used to print messages and strings to the output stream, specifying also the stream you want to use. Different standard colors are set for each output-stream type. If the output stream is not specified std::cout will be used as default. This overload is used for the general case.
   * 
   * @tparam Args The parameter pack of the various types.
   * @param os The output stream.
   * @param args One or more objects to be printed.
   */
  template <typename... Args>
  inline void print( std::ostream& os = agr::null_stream, const Args&... args )
   {
    if( &os == &agr::null_stream ) std::cout << "\n";
    else if( &os == &std::cerr ) os << feat( col, "red" ) << feat( sty, "bold" );
    else if( &os == &std::clog ) os << feat( col, "lt blue" ) << feat( sty, "bold" );

    ( os << ... << args ) << "\n";

    if( &os == &std::cerr || &os == &std::clog || &os == &std::cout ) os << reset( "all" );
   }
  
  //====================================================
  //     print (second overload)
  //====================================================
  /**
   * @brief It can be used to print messages and strings in the output stream, specifying also the stream you want to use. Different standard colors are set for each output-stream type. If the output stream is not specified std::cout will be used as default. This overload is used for the 0-arguments case.
   * 
   * @tparam Args The parameter pack of the various types.
   * @param args One or more objects to be printed.
   */
  template <typename... Args>
  inline void print( Args&... args )
   {
    ( std::cout << ... << args ) << "\n" << reset( "all" );
   }
 }

#endif