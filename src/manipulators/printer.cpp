//====================================================
//     Headers
//====================================================

//My headers
#include "../include/manipulators/printer.hpp"
#include "../include/manipulators/colsty.hpp"

//Extra headers
#include <arsenalgear/utils.hpp>

//STD headers
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

namespace osm
 {
  //====================================================
  //     Default constructor
  //====================================================
  /**
   * @brief Default constructor of OS_Decorator class.
   * 
   */
  OS_Decorator::OS_Decorator(){}

  //====================================================
  //     Destructor
  //====================================================
  /**
   * @brief Destructor of OS_Decorator class.
   * 
   */
  OS_Decorator::~OS_Decorator()
   {
    std::cout << reset( "all" );
   }

  //====================================================
  //     setColor
  //====================================================
  /**
   * @brief Method used to set the color of a stream.
   * 
   * @param color The color to be set for the stream.
   * @param os The stream to be modified. Default is std::cout.
   */
  void OS_Decorator::setColor( const std::string& color, std::ostream& os )
   {
    if( colors.count( &os ) == 1 ) colors[ &os ] = color;
    else colors.insert( { &os, color } );
   }

  //====================================================
  //     setStyle
  //====================================================
  /**
   * @brief Method used to set the style of a stream.
   * 
   * @param color The style to be set for the stream.
   * @param os The stream to be modified. Default is std::cout.
   */
  void OS_Decorator::setStyle( const std::string& style, std::ostream& os )
   {
    if( styles.count( &os ) == 1 ) styles[ &os ] = style;
    else styles.insert( { &os, style } );
   }

  //====================================================
  //     resetColor
  //====================================================
  /**
   * @brief Method used to reset the color of a stream.
   * 
   * @param color The color to be reset for the stream.
   * @param os The stream to be modified. Default is std::cout.
   */
  void OS_Decorator::resetColor( std::ostream& os )
   {
    colors.erase( &os );
   }

  //====================================================
  //     resetStyle
  //====================================================
  /**
   * @brief Method used to reset the style or of a stream.
   * 
   * @param color The style to be reset for the stream.
   * @param os The stream to be modified. Default is std::cout.
   */
  void OS_Decorator::resetStyle( std::ostream& os )
   {
    styles.erase( &os );
   }

  //====================================================
  //     resetFeatures
  //====================================================
  /**
   * @brief Method used to reset all the features of a stream.
   * 
   * @param os The stream to be modified. Default is std::cout.
   */
  void OS_Decorator::resetFeatures( std::ostream& os )
   {
    colors.erase( &os );
    styles.erase( &os );
    os << reset( "all" );
   }

  //====================================================
  //     getColor
  //====================================================
  /**
   * @brief Method used to return the selected color of a stream.
   * 
   * @param os The stream which color is returned. Default is std::cout.
   * 
   * @return std::string The current color of the stream.
   */
  std::string OS_Decorator::getColor( std::ostream& os )
   {
    return colors[ &os ];
   }

  //====================================================
  //     getStyle
  //====================================================
  /**
   * @brief Method used to return the selected style of a stream.
   * 
   * @param os The stream which style is returned. Default is std::cout.
   * 
   * @return std::string The current style of the stream.
   */
  std::string OS_Decorator::getStyle( std::ostream& os )
   {
    return styles[ &os ];
   }

  //====================================================
  //     getColorList
  //====================================================
  /**
   * @brief Method used to return the map of streams with the respective color.
   * 
   * @return std::map <std::ostream*, std::string> The stream-color map.
   */
  std::map <std::ostream*, std::string> OS_Decorator::getColorList()
   {
    return colors;
   }

  //====================================================
  //     getStyleList
  //====================================================
  /**
   * @brief Method used to return the map of streams with the respective style.
   * 
   * @return std::map <std::ostream*, std::string> The stream-color map.
   */
  std::map <std::ostream*, std::string> OS_Decorator::getStyleList()
   {
    return styles;
   }

  //====================================================
  //     getCurrentStream
  //====================================================
  /**
   * @brief Method used to return the stream that is used to output stuff.
   * 
   * @return std::ostream& The used stream to output stuff.
   */
  std::ostream& OS_Decorator::getCurrentStream()
   {
    return *current_stream;
   }

  //====================================================
  //     operator ()
  //====================================================
  /**
   * @brief Operator overload to assign the value into parentheses to the "current_stream" variable.
   * 
   * @param os Input value, i.e. the stream put into parentheses.
   * @return const OS_Decorator& The class pointer.
   */
  const OS_Decorator& OS_Decorator::operator () ( std::ostream& os )
   {
    current_stream = &os;
    return *this;
   }
 }