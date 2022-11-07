//====================================================
//     File data
//====================================================
/**
 * @file decorator.cpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

//My headers
#include "../../include/utility/iostream.hpp"
#include "../../include/manipulators/decorator.hpp"
#include "../../include/manipulators/colsty.hpp"
#include "../../include/manipulators/common.hpp"

//STD headers
#include <string>
#include <unordered_map>

namespace osm
 {
  //====================================================
  //     Constructors
  //====================================================
  /**
   * @brief Default constructor of Decorator class.
   * 
   */
  Decorator::Decorator(){}

  //====================================================
  //     Destructor
  //====================================================
  /**
   * @brief Destructor of Decorator class.
   * 
   */
  Decorator::~Decorator()
   {
    osm::cout << feat( rst, "all" );
   }

  //====================================================
  //     Setters
  //====================================================

  // setColor
  /**
   * @brief Method used to set the color of a stream.
   * 
   * @param color The color to be set for the stream.
   * @param os The stream to be modified. Default is osm::cout.
   */
  void Decorator::setColor( const std::string& color, std::ostream& os )
   {
    if( colors.count( &os ) == 1 ) colors[ &os ] = color;
    else colors.insert( { &os, color } );
   }

  // setStyle
  /**
   * @brief Method used to set the style of a stream.
   * 
   * @param color The style to be set for the stream.
   * @param os The stream to be modified. Default is osm::cout.
   */
  void Decorator::setStyle( const std::string& style, std::ostream& os )
   {
    if( styles.count( &os ) == 1 ) styles[ &os ] = style;
    else styles.insert( { &os, style } );
   }

  // resetColor
  /**
   * @brief Method used to reset the color of a stream.
   * 
   * @param color The color to be reset for the stream.
   * @param os The stream to be modified. Default is osm::cout.
   */
  void Decorator::resetColor( std::ostream& os )
   {
    colors.erase( &os );
   }

  // resetStyle
  /**
   * @brief Method used to reset the style or of a stream.
   * 
   * @param color The style to be reset for the stream.
   * @param os The stream to be modified. Default is osm::cout.
   */
  void Decorator::resetStyle( std::ostream& os )
   {
    styles.erase( &os );
   }

  // removeStyle
  /**
   * @brief Method used to remove one of the set styles (useful in case they are more than one).
   * 
   * @param color The style to be reset for the stream.
   * @param os The stream to be modified. Default is osm::cout.
   */
  void Decorator::removeStyle( const std::string& style, std::ostream& os )
   {
    std::string str_mod = styles.at( &os );
    std::string::size_type sub_str = str_mod.find( style );

    styles.at( &os ) = str_mod.erase( sub_str, style.length() );

    if ( getStyleList()[ &os ][0] == ' ' ) styles.at( &os ).erase( 0, 1 );
    else if ( getStyleList()[ &os ].back() == ' ' ) styles.at( &os ).pop_back();

   }

  // resetFeatures
  /**
   * @brief Method used to reset all the features of a stream.
   * 
   * @param os The stream to be modified. Default is osm::cout.
   */
  void Decorator::resetFeatures( std::ostream& os )
   {
    colors.erase( &os );
    styles.erase( &os );
    os << feat( rst, "all" );
   }

  //====================================================
  //     Getters
  //====================================================

  // getColor
  /**
   * @brief Method used to return the selected color of a stream.
   * 
   * @param os The stream which color is returned. Default is osm::cout.
   * 
   * @return std::string The current color of the stream.
   */
  std::string Decorator::getColor( std::ostream& os )
   {
    return colors[ &os ];
   }

  // getStyle
  /**
   * @brief Method used to return the selected style of a stream.
   * 
   * @param os The stream which style is returned. Default is osm::cout.
   * 
   * @return std::string The current style of the stream.
   */
  std::string Decorator::getStyle( std::ostream& os )
   {
    return styles[ &os ];
   }

  // getColorList
  /**
   * @brief Method used to return the map of streams with the respective color.
   * 
   * @return std::map <std::ostream*, std::string> The stream-color map.
   */
  std::unordered_map <std::ostream*, std::string> Decorator::getColorList()
   {
    return colors;
   }

  // getStyleList
  /**
   * @brief Method used to return the map of streams with the respective style.
   * 
   * @return std::map <std::ostream*, std::string> The stream-color map.
   */
  std::unordered_map <std::ostream*, std::string> Decorator::getStyleList()
   {
    return styles;
   }

  // getCurrentStream
  /**
   * @brief Method used to return the stream that is used to output stuff.
   * 
   * @return std::ostream& The used stream to output stuff.
   */
  std::ostream& Decorator::getCurrentStream()
   {
    return *current_stream;
   }

  //====================================================
  //     Operators
  //====================================================

  // operator ()
  /**
   * @brief Operator overload to assign the value into parentheses to the "current_stream" variable.
   * 
   * @param os Input value, i.e. the stream put into parentheses.
   * @return const Decorator& The class pointer.
   */
  const Decorator& Decorator::operator () ( std::ostream& os )
   {
    current_stream = &os;
    return *this;
   }
 }