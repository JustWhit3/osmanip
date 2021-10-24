#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include "../include/osmanip.h"


//-----------------------------------------   DEFINITIONS   -----------------------------------------


//Definition of the color map:
std::map <std::string, std::string> col 
 {
  { "error", "Inserted color is not supported!\n" }, { "reset", "\033[0m" },
  { "black", "\033[30m" }, { "red", "\033[31m" }, { "green", "\033[32m" }, { "orange", "\033[33m" }, { "blue", "\033[34m" }, { "magenta", "\033[35m" }, 
  { "cyan", "\033[36m" }, { "white", "\033[37m" }, { "hl green 1", "\033[40m" }, { "hl green 2", "\033[42m" }, { "hl green 3", "\033[46m" }, 
  { "hl red", "\033[41m" }, { "hl yellow", "\033[43m" }, { "hl cyan", "\033[44m" }, { "hl grey", "\033[45m" }, { "hl white", "\033[47m" }
 };

//Definition of the style map:
std::map <std::string, std::string> sty 
 {
  { "error", "Inserted style is not supported!\n" }, { "reset", "\033[0m" },
  { "bold", "\033[1m" }, { "faint", "\033[2m" }, { "italics", "\033[3m" }, { "underlined", "\033[4m" }, { "highlighted", "\033[7m" }, 
  { "invisible", "\033[8m" }, { "striped", "\033[9m" }
 };
 
//Definiton of the feature function:
std::string feat( std::map <std::string, std::string> & generic_map, std::string feat )
 {
  if ( generic_map.find( feat ) == generic_map.end() ) 
   {
    throw std::runtime_error( generic_map.at( "error" ) );
   } 
  else
   {
    return generic_map.at( feat );
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

