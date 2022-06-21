//====================================================
//     Preprocessor settings
//====================================================
#ifndef CSMANIP_HPP
#define CSMANIP_HPP

//====================================================
//     Headers
//====================================================

//Extra headers
#include <arsenalgear/stream.hpp>

//STD headers
#include <iostream>
#include <string>
#include <map>
#include <set>

namespace osm
 {
  //====================================================
  //     Aliases
  //====================================================
  using string_pair_map = std::map <std::string, std::pair<std::string, std::string>>;
  using string_set_map = std::map <std::string, std::set <std::string> >;

  //====================================================
  //     CURSOR
  //====================================================
  /**
   * @brief It is used to store the OPTION function options for the cursor view. Current options are: ON to enable cursor view and OFF to disable it.
   * 
   */
  enum class CURSOR { ON, OFF };

  //====================================================
  //     Variables
  //====================================================
  extern const std::map <std::string, std::string> col, sty, rst, tcs;
  extern const string_pair_map crs, tcsc;

  //====================================================
  //     Functions
  //====================================================
  extern std::string feat( const std::map <std::string, std::string>& generic_map, const std::string& feat_string );
  extern std::string feat( const string_pair_map& generic_map, const std::string& feat_string, const int& feat_int );
  extern std::string reset( const std::string& reset_string );
  extern std::string go_to( const int& x, const int& y );
  extern std::string RGB( const int& r, const int& g, const int& b );

  //====================================================
  //     OPTION
  //====================================================
  /**
   * @brief It is used to set the cursor view.
   * 
   * @tparam T The type of the given option.
   * @param option The option to set.
   * @return std::string The string (option) to be printed.
   */
  template <typename T>
  inline void OPTION( const T& opt )
   {
    if( opt == CURSOR::ON ) std::cout << feat( tcs, "scrs" );
    else if( opt == CURSOR::OFF ) std::cout << feat( tcs, "hcrs" ); 
    else std::cerr << feat( col, "red" ) << "Inserted cursor option is not supported!"  << reset( "all" ) << "\n";
   }

  //====================================================
  //     print
  //====================================================
  /**
   * @brief It can be used to print messages and strings in the output stream, specifying also the stream you want to use. Different standard colors are set for each output-stream type. If the output stream is not specified std::cout will be used as default. This overload is used for the general case.
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