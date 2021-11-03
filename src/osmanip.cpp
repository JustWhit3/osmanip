#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include "../include/osmanip.h"


//-----------------------------------------   DEFINITIONS   -----------------------------------------


//Definition of the "color" map:
std::map <std::string, std::string> col 
 {
  //Error variables:
  { "error", "Inserted color" },
  
  //Color variables:
  { "black", "\033[30m" }, { "red", "\033[31m" }, { "green", "\033[32m" }, { "orange", "\033[33m" }, 
  { "blue", "\033[34m" }, { "purple", "\033[35m" }, { "cyan", "\033[36m" }, { "gray", "\033[37m" }, 
  { "dk gray", "\033[90m" }, { "lt red", "\033[91m" },  { "lt green", "\033[92m" }, { "yellow", "\033[93m" },
  { "lt blue", "\033[94m"}, { "lt purple", "\033[95m" }, { "lt cyan", "\033[96m" }, { "white", "\033[97m" },
  
  //Background color variables:
  { "bg black", "\033[40m" }, { "bg red", "\033[41m" }, { "bg green", "\033[42m" }, { "bg orange", "\033[43m" },
  { "bg cyan", "\033[44m" }, { "bg purple", "\033[45m" }, { "bg blue", "\033[46m" }, { "bg gray", "\033[47m" },
  { "bg dk gray", "\033[100m"}, { "bg lt red", "\033[101m" },  { "bg lt green", "\033[102m" }, { "bg yellow", "\033[103m" },
  { "bg lt blue", "\033[104m"}, { "bg lt purple", "\033[105m" }, { "bg lt cyan", "\033[106m" }, { "bg white", "\033[107m" },
  
  //Bold color variables:
  { "bd black", "\033[1;30m"}, { "bd red", "\033[1;31m" }, { "bd green", "\033[1;32m" }, { "bd orange", "\033[1;33m" }, 
  { "bd blue", "\033[1;34m" }, { "bd purple", "\033[1;35m"}, { "bd cyan", "\033[1;36m" }, { "bd gray", "\033[1;37m" }
 };

//Definition of the "style" map:
std::map <std::string, std::string> sty 
 {
  //Error variables:
  { "error", "Inserted style" },
  
  //Color variables:
  { "bold", "\033[1m" }, { "faint", "\033[2m" }, { "italics", "\033[3m" }, { "underlined", "\033[4m" }, 
  { "blink", "\033[5m" }, { "inverse", "\033[7m" }, { "invisible", "\033[8m" }, { "crossed", "\033[9m" },
  {"d-underlined", "\033[21m" }
 };
 
//Definition of the "reset" map:
std::map <std::string, std::string> rst 
 {
  //Error variables:
  { "error", "Inserted reset command" },
  
  //Reset total variables:
  { "all", "\033[0m" },
  
  //Reset color variables:
  { "color", "\033[39m" }, { "bg color", "\033[49m" }, {"bd color", "\033[22m \033[39m"  },
  
  //Reset style variables:
  { "bd/ft", "\033[22m" }, { "italics", "\033[23m" }, { "underlined", "\033[24m" }, { "blink", "\033[25m" }, 
  { "inverse", "\033[27m" }, { "invisible", "\033[28m" }, { "crossed", "\033[29m" },
 };
 
//Definition of the "cursor" map:
std::map <std::string, std::string> crs
 {
  //Error variables:
  { "error", "Inserted cursor command" },
  
  //Cursor variables:
  { "up", "\u001b[A" }, { "down", "\u001b[B" }, { "right", "\u001b[C" }, { "left", "\u001b[D" }
 };
 
//Definiton of the "feat" function:
std::string feat( std::map <std::string, std::string> & generic_map, std::string feat_string )
 {
  if ( generic_map.find( feat_string ) == generic_map.end() ) 
   {
    std::string conct;
    conct.append( generic_map.at( "error" ) );
    conct.append( " \"" );
    conct.append( feat_string );
    conct.append( "\" is not supported!\n" );
    throw std::runtime_error( conct );
   } 
  else
   {
    return generic_map.at( feat_string );
   }
 }
 
//Definition of the "reset" function
std::string reset ( std::string reset_string )
 {
  if ( rst.find( reset_string ) == rst.end() ) 
   {
    std::string conct;
    conct.append( rst.at( "error" ) );
    conct.append( " \"" );
    conct.append( reset_string );
    conct.append( "\" is not supported!\n" );
    throw std::runtime_error( conct );
   } 
  else
   {
    return rst.at( reset_string );
   }
 }
 
 
//-----------------------------------------   TESTINGS   -----------------------------------------


//Definition of the "feat" function testing function:
void feat_test( std::map <std::string, std::string> & generic_map_test  )
 {
  for( auto & element: generic_map_test )
   {
    if( generic_map_test.find( element.first ) == generic_map_test.end() )
     {
      bool exceptionThrown = false;
      try 
       {
        feat( generic_map_test, element.first );
       } 
      catch( std::runtime_error & )
       {
        exceptionThrown = true;
       }
      assert( exceptionThrown &&
      "Function \"feat\" didn't return runtime error if an invalid feature is inserted!" );
     }
    else
     {
      assert( feat( generic_map_test, element.first ) == generic_map_test.at( element.first ) &&
     "Function \"feat\" didn't return the correct feature!" );
     }
   }
 }
 
//Definition of the "reset" function testing function:
void reset_test ()
 {
  for( auto & element: rst )
   {
    if( rst.find( element.first ) == rst.end() )
     {
      bool exceptionThrown = false;
      try 
       {
        reset( element.first );
       } 
      catch( std::runtime_error & )
       {
        exceptionThrown = true;
       }
      assert( exceptionThrown &&
      "Function \"reset\" didn't return runtime error if an invalid reset command is inserted!" );
     }
    else
     {
      assert( reset( element.first ) == rst.at( element.first ) &&
     "Function \"reset\" didn't return the correct reset command!" );
     }
   }
 }

