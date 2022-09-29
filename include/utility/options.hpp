//====================================================
//     File data
//====================================================
/**
 * @file options.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_OPTIONS_HPP
#define OSMANIP_OPTIONS_HPP

//====================================================
//     Headers
//====================================================

//My headers
#include "../utility/windows.hpp"
#include "../manipulators/cursor.hpp"
#include "../manipulators/colsty.hpp"

//STD headers
#include <iostream>
#include <type_traits>

namespace osm
 {
  //====================================================
  //     Enum classes
  //====================================================

  // CURSOR
  /**
   * @brief It is used to store the OPTION function options for the cursor view. Current options are: ON to enable cursor view and OFF to disable it.
   * 
   */
  enum class CURSOR { ON, OFF };

  // ANSI
  /**
   * @brief It is used to store the OPTION function options for the ANSI escape sequences enabling. Current options are: ON to enable and OFF to disable.
   * 
   */
  enum class ANSI { ON, OFF };

  // UNICODECH
  /**
   * @brief It is used to store the OPTION function options for the UNICODE characters enabling. Current options are: ON to enable and OFF to disable.
   * 
   */
  enum class UNICODECH { ON, OFF };

  //====================================================
  //     Functions
  //====================================================

  // OPTION
  /**
   * @brief It is used to set a specific option.
   * 
   * @tparam T The type of the given option.
   * @param opt The option to be set.
   * @return void Set the chosen option.
   */
  template <typename T>
  inline void OPTION( T opt ) 
   {
    if constexpr ( std::is_same_v<T, CURSOR> ) 
     {
      if ( opt == CURSOR::ON ) std::cout << feat( tcs, "scrs" );
      else if ( opt == CURSOR::OFF ) std::cout << feat( tcs, "hcrs" ); 
     } 
    else if constexpr ( std::is_same_v<T, ANSI> ) 
     {
      if ( opt == ANSI::ON ) enableANSI();
      else if ( opt == ANSI::OFF ) disableANSI();
     }
    else if constexpr ( std::is_same_v<T, UNICODECH> ) 
     {
      if ( opt == UNICODECH::ON ) enableUNICODE();
      else if ( opt == UNICODECH::OFF ) disableUNICODE();
     }
    else std::cerr << feat( col, "red" ) << "Inserted cursor option is not supported!"  << feat( rst, "all" ) << "\n";
   }
 }

#endif