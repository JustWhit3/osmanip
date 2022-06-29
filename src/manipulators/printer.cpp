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
    for ( const auto& elem_col: colors ) *elem_col.first << reset( "all" );
    for ( const auto& elem_sty: styles ) *elem_sty.first << reset( "all" );
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

    os << feat( col, colors[ &os ] );
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

    os << feat( sty, styles[ &os ] );
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
  void OS_Decorator::resetColor( const std::string& color_type, std::ostream& os )
   {
    std::vector <std::string> colors_container { "color", "bg color", "bd color" };

    if ( ! std::count( colors_container.begin(), colors_container.end(), color_type ) )
     {
      throw agr::except_error_func( rst.at( "error" ), color_type, "is not supported!" );
     }

    colors.erase( colors.find( &os ) );
    os << reset( color_type );
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
  void OS_Decorator::resetStyle( const std::string& style_type, std::ostream& os )
   {
    std::vector <std::string> styles_container { "bd/ft", "italics", "underlined", "blink", "inverse", "invisible", "crossed" };

    if ( ! std::count( styles_container.begin(), styles_container.end(), style_type ) )
     {
      throw agr::except_error_func( rst.at( "error" ), style_type, "is not supported!" );
     }

    styles.erase( &os );
    os << reset( style_type );
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
 }