//====================================================
//     File data
//====================================================
/**
 * @file colsty.cpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

//My headers
#include "../../include/manipulators/colsty.hpp"

//STD headers
#include <string>
#include <unordered_map>
#include <sstream>

namespace osm
 {
  //====================================================
  //     Variables
  //====================================================

  // col
  /**
   * @brief It is used to store the colors. Note: "bg" is the prefix of the background color features and "bd" is the one of the bold color features.
   * 
   */
  const std::unordered_map <std::string, std::string> col 
   {
    //Error variables:
    { "error", "Inserted color" },
  
    //Color variables:
    { "black", "\033[30m" },
    { "red", "\033[31m" },
    { "green", "\033[32m" },
    { "orange", "\033[33m" }, 
    { "blue", "\033[34m" },
    { "purple", "\033[35m" },
    { "cyan", "\033[36m" },
    { "gray", "\033[37m" }, 
    { "dk gray", "\033[90m" },
    { "lt red", "\033[91m" }, 
    { "lt green", "\033[92m" },
    { "yellow", "\033[93m" },
    { "lt blue", "\033[94m"},
    { "lt purple", "\033[95m" },
    { "lt cyan", "\033[96m" },
    { "white", "\033[97m" },
  
    //Background color variables:
    { "bg black", "\033[40m" },
    { "bg red", "\033[41m" },
    { "bg green", "\033[42m" },
    { "bg orange", "\033[43m" },
    { "bg cyan", "\033[44m" },
    { "bg purple", "\033[45m" },
    { "bg blue", "\033[46m" },
    { "bg gray", "\033[47m" },
    { "bg dk gray", "\033[100m"},
    { "bg lt red", "\033[101m" },
    { "bg lt green", "\033[102m" },
    { "bg yellow", "\033[103m" },
    { "bg lt blue", "\033[104m"},
    { "bg lt purple", "\033[105m" },
    { "bg lt cyan", "\033[106m" },
    { "bg white", "\033[107m" },
  
    //Bold color variables:
    { "bd black", "\033[1;30m"},
    { "bd red", "\033[1;31m" },
    { "bd green", "\033[1;32m" },
    { "bd orange", "\033[1;33m" }, 
    { "bd blue", "\033[1;34m" },
    { "bd purple", "\033[1;35m"},
    { "bd cyan", "\033[1;36m" },
    { "bd gray", "\033[1;37m" }
   };

  // sty
  /**
   * @brief It is used to store the styles.
   * 
   */
  const std::unordered_map <std::string, std::string> sty 
   {
    //Error variables:
    { "error", "Inserted style" },
  
    //Style variables:
    { "bold", "\033[1m" },
    { "faint", "\033[2m" },
    { "italics", "\033[3m" },
    { "underlined", "\033[4m" }, 
    { "blink", "\033[5m" },
    { "inverse", "\033[7m" },
    { "invisible", "\033[8m" },
    { "crossed", "\033[9m" },
    { "d-underlined", "\033[21m" }
   };
 
  // rst
  /**
   * @brief It is used to store the reset features commands.
   * 
   */
  const std::unordered_map <std::string, std::string> rst 
   {
    //Error variables:
    { "error", "Inserted reset command" },
  
    //Reset total variables:
    { "all", "\033[0m" },
  
    //Reset color variables:
    { "color", "\033[39m" },
    { "bg color", "\033[49m" },
    { "bd color", "\033[22m \033[39m" },
  
    //Reset style variables:
    { "bd/ft", "\033[22m" },
    { "italics", "\033[23m" },
    { "underlined", "\033[24m" },
    { "blink", "\033[25m" }, 
    { "inverse", "\033[27m" },
    { "invisible", "\033[28m" },
    { "crossed", "\033[29m" },
   };

  //====================================================
  //     Functions
  //====================================================

  // RGB
  /**
   * @brief It takes three integers as arguments which are the corresponding rgb triplets of a color (see here for the full list of available colors http://www.aksiom.net/rgb.html). It can be used to output a wider variety of colors with respect to the standard available from the col map.
   * 
   * @param r The r singlet of the tripled.
   * @param g The g singlet of the tripled.
   * @param b The b singlet of the tripled.
   * @return const std::string The rgb triplet of the color.
   */
  const std::string RGB( int r, int g, int b )
   {
    static std::ostringstream oss;
    oss.str( "" );
    oss.clear();
    oss << "\x1b[38;2;" << r << ";" << g << ";" << b << "m";

    return oss.str();
   }
 }