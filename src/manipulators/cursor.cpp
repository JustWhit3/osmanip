//====================================================
//     Headers
//====================================================

//My headers
#include "../include/manipulators/cursor.hpp"

//Extra headers
#include <arsenalgear/utils.hpp>

//STD headers
#include <string>
#include <unordered_map>
#include <set>

//====================================================
//     Namespaces
//====================================================
using namespace std::literals::string_literals;

namespace osm
 {  
  //====================================================
  //     crs
  //====================================================
  /**
   * @brief It is used to store the cursor commands.
   * 
   */
  const string_pair_map crs
   {
    //Error variables:
    { "error", std::make_pair( "Inserted cursor command", "" ) },
  
    //Cursor variables:
    { "up", std::make_pair( "\u001b[", "A" ) },
    { "down", std::make_pair( "\u001b[", "B" ) }, 
    { "right", std::make_pair( "\u001b[", "C" ) },
    { "left", std::make_pair( "\u001b[", "D" ) }
   };

  //====================================================
  //     tcs
  //====================================================
  /**
   * @brief It is used to store the terminal control sequences.
   * 
   */
  const std::unordered_map <std::string, std::string> tcs
   {
    //Error variables:
    { "error", "Inserted terminal control sequence" },

    //Control characters variables:
    { "bell", "\x07" },     //Bell sound
    { "bksp", "\x08" },     //Backspace
    { "tab", "\x09" },      //Tab
    { "lfd", "\x0A" },      //Line feed
    { "ffd", "\x0C" },      //Form feed
    { "crt", "\x0D" },      //Carriage return

    //Control sequences variables:
    { "hcrs", "\u001b[?25l" },            //Hide cursor
    { "scrs", "\u001b[?25h" }             //Show cursor
   };

  //====================================================
  //     tcsc
  //====================================================
  /**
   * @brief It is used to store the terminal control sequences for clear line / screen.
   * 
   */
  const string_pair_map tcsc
   {
    //Error variables:
    { "error", std::make_pair( "Inserted terminal control sequence", "" ) },

    //Control sequences variables:
    { "csc", std::make_pair( "\u001b[", "J" ) },  //Clear screen (0,1,2)
    { "cln", std::make_pair( "\u001b[", "K" ) }  //Clear line (0,1,2)
   };

  //====================================================
  //     feat (second overload)
  //====================================================
  /**
   * @brief This overload, with respect to the standard function definition, takes an std::map object as the first argument, but with an std::pair as second type and additionally takes an extra integer argument to correctly set the parameter of the crs map.
   * 
   * @param generic_map The feature map.
   * @param feat_string The feature name.
   * @param feat_int Extra integer argument to correctly set the parameter of the crs map.
   * @return std::string The output feature.
   */
  std::string feat( const string_pair_map& generic_map, const std::string& feat_string, const int& feat_int )
   {
    if( generic_map.find( feat_string ) == generic_map.end() ) 
     {
      throw agr::except_error_func( generic_map.at( "error" ).first, feat_string, "is not supported!" );
     }
    else
     {
      if( generic_map == crs || generic_map == tcsc )
       {
        return generic_map.at( feat_string ).first + 
               std::to_string( feat_int ) + 
               generic_map.at( feat_string ).second;
       }
      return generic_map.at( feat_string ).first;
     }
   }

  //====================================================
  //     go_to
  //====================================================
  /**
   * @brief It takes two integers as arguments which are the x and y position of the cursor in the screen and returns the interested position you want to reach.
   * 
   * @param x The x position of the cursor in the screen.
   * @param y The y position of the cursor in the screen
   * @return std::string The (x,y) position of the cursor in the screen.
   */
  std::string go_to( const int& x, const int& y )
   {
    return "\u001b[" + 
           std::to_string( x ) + ";"s +
           std::to_string( y ) + "H"s;
   }
 }