//====================================================
//     Preprocessor settings
//====================================================
#ifndef PRINTER_HPP
#define PRINTER_HPP

//====================================================
//     Headers
//====================================================

//My headers
#include "common.hpp"
#include "colsty.hpp"

//Extra headers
#include <arsenalgear/stream.hpp>

//STD headers
#include <iostream>
#include <vector>
#include <string>

namespace osm
 {
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

  //====================================================
  //     OS_Decorator class
  //====================================================
  /**
   * @brief Class used to decorate an output stream. Each setting is set permanently on the chosen output stream until the destructor is met or one of the reset functions is called.
   * 
   */
  class OS_Decorator
   {
    public:

     //====================================================
     //     Constructors and destructors
     //====================================================
     OS_Decorator();
     ~OS_Decorator();
 
     //====================================================
     //     Setters
     //====================================================
     void setColor( const std::string& color, std::ostream& os = std::cout );
     void setStyle( const std::string& style, std::ostream& os = std::cout );
 
     //====================================================
     //     Resetters
     //====================================================
     void resetColor( const std::string& color_type, std::ostream& os = std::cout );
     void resetStyle( const std::string& style_type, std::ostream& os = std::cout );
     void resetFeatures( std::ostream& os = std::cout );
 
     //====================================================
     //     Getters
     //====================================================
     std::string getColor( std::ostream& os = std::cout );
     std::string getStyle( std::ostream& os = std::cout );
     std::map <std::ostream*, std::string> getColorList();
     std::map <std::ostream*, std::string> getStyleList();

    private:

     //====================================================
     //     Attributes
     //====================================================
     std::map <std::ostream*, std::string> colors, styles;
   };
 }

#endif