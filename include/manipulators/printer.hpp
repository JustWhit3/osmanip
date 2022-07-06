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
     void resetColor( std::ostream& os = std::cout );
     void resetStyle( std::ostream& os = std::cout );
     void resetFeatures( std::ostream& os = std::cout );
 
     //====================================================
     //     Getters
     //====================================================
     std::string getColor( std::ostream& os = std::cout );
     std::string getStyle( std::ostream& os = std::cout );
     std::map <std::ostream*, std::string> getColorList();
     std::map <std::ostream*, std::string> getStyleList();
     std::ostream& getCurrentStream();

     //====================================================
     //     Operators
     //====================================================
     const OS_Decorator& operator () ( std::ostream& os = std::cout );

    private:

     //====================================================
     //     Attributes
     //====================================================
     std::map <std::ostream*, std::string> colors, styles;
     std::ostream* current_stream;
   };

  //====================================================
  //     Operator << 
  //====================================================
  /**
   * @brief Operator overload to output a modified ostream object which properties are set thanks to the OS_Decorator class.
   * 
   * @tparam T The template parameter of the object sent into the output stream.
   * @param my_shell The OS_Decorator object.
   * @param elem The element sent into the output stream.
   * @return std::ostream& The modified output stream.
   */
  template <typename T>
  std::ostream& operator << ( OS_Decorator my_shell, const T& elem )
   {
    if ( my_shell.getColor( my_shell.getCurrentStream() ) != "" )
     {
      my_shell.getCurrentStream() << feat( col, my_shell.getColor( my_shell.getCurrentStream() ) );
     }
    if ( my_shell.getStyle( my_shell.getCurrentStream() ) != "" )
     {
      my_shell.getCurrentStream() << feat( sty, my_shell.getStyle( my_shell.getCurrentStream() ) );
     }
    my_shell.getCurrentStream() << elem << reset( "all" );
    
    return my_shell.getCurrentStream();
   }
 }

#endif