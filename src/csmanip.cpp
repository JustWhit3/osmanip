#include <iostream>
#include <string>
#include <map>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>

#include "../include/csmanip.hpp"
#include "../include/helper_tools.hpp"

#define ARGS( ... ) BOOST_PP_TUPLE_TO_SEQ( ( __VA_ARGS__ ) )

namespace osm
 {
  //====================================================
  //     DEFINITION OF THE "color" MAP
  //====================================================
  std::map <std::string, std::string> col 
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

  //====================================================
  //     DEFINITION OF THE "style" MAP
  //====================================================
  //Definition of the "style" map:
  std::map <std::string, std::string> sty 
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
 
  //====================================================
  //     DEFINITION OF THE "reset" MAP
  //====================================================
  std::map <std::string, std::string> rst 
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
  //     DEFINITION OF THE "tcs" MAP
  //     (terminal control sequences)
  //====================================================
  std::map <std::string, std::string> tcs
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
  //     DEFINITION OF THE "tcsc" MAP
  //====================================================
  string_pair_map tcsc
   {
    //Error variables:
    { "error", std::make_pair( "Inserted cursor command", "" ) },

    //Control sequences variables:
    { "csc", std::make_pair( "\u001b[", "J" ) },  //Clear screen (0,1,2)
    { "cln", std::make_pair( "\u001b[", "K" ) }  //Clear line (0,1,2)
   };
 
  //====================================================
  //     DEFINITION OF THE "cursor" MAP
  //====================================================
  string_pair_map crs
   {
    //Error variables:
    { "error", std::make_pair( "Inserted terminal control sequence", "" ) },
  
    //Cursor variables:
    { "up", std::make_pair( "\u001b[", "A" ) },
    { "down", std::make_pair( "\u001b[", "B" ) }, 
    { "right", std::make_pair( "\u001b[", "C" ) },
    { "left", std::make_pair( "\u001b[", "D" ) }
   };
 
  //====================================================
  //     DEFINITION OF THE "feat" FUNCTION
  //====================================================
  std::string feat( std::map <std::string, std::string> & generic_map, std::string feat_string )
   {
    if( generic_map.find( feat_string ) == generic_map.end() ) 
     {
      throw runtime_error_func( generic_map.at( "error" ), feat_string, "is not supported!" );
     }
    return generic_map.at( feat_string );
   }

  //====================================================
  //     DEFINITION OF THE "feat" FUNCTION OVERLOAD
  //     (for the crs map)
  //====================================================
  std::string feat( string_pair_map & generic_map, std::string feat_string, int feat_int )
   {
    if( generic_map.find( feat_string ) == generic_map.end() ) 
     {
      throw runtime_error_func( generic_map.at( "error" ).first, feat_string, "is not supported!" );
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
  //     DEFINITION OF THE "reset" FUNCTION
  //====================================================
  std::string reset( std::string reset_string )
   {
    if( rst.find( reset_string ) == rst.end() ) 
     {
      throw runtime_error_func( rst.at( "error" ), reset_string, "is not supported!" );
     } 
    return rst.at( reset_string );
   }

  //====================================================
  //     DEFINITION OF THE "go_to" FUNCTION
  //====================================================
  std::string go_to( int x, int y )
   {
    return "\u001b[" + 
           std::to_string( x ) + 
           static_cast <std::string>( ";" ) +
           std::to_string( y ) +
           static_cast <std::string>( "H" );
   }

  //====================================================
  //     DEFINITION OF THE "RGB" FUNCTION
  //====================================================
  std::string RGB( int r, int g, int b )
   {
    return "\x1b[38;2;" +
            std::to_string( r ) + 
            static_cast <std::string>( ";" ) +
            std::to_string( g ) +
            static_cast <std::string>( ";" ) +
            std::to_string( b ) +
            static_cast <std::string>( "m" );
   }

  //====================================================
  //     DEFINITION OF THE "OPTION" FUNCTION
  //====================================================
  template <typename T>
  void OPTION( const T opt )
   {
    if( opt == CURSOR::ON )
     {
      std::cout << feat( tcs, "scrs" );
     }
    else if( opt == CURSOR::OFF )
     {
      std::cout << feat( tcs, "hcrs" ); 
     }
    else
     {
      throw runtime_error_func( "Inserted cursor option", "", "is not supported!" );
     }
   }

  //Explicit instantiations:
  #define OPTION( r, data, T ) template \
  void OPTION <T> ( const T opt );

  BOOST_PP_SEQ_FOR_EACH( OPTION, _, ARGS( CURSOR ) );
 }