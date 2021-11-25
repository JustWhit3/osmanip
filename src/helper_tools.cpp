#include <iostream>
#include <string>
#include <map>
#include <set>
#include "../include/helper_tools.h"
  
namespace osm
 {
  //Operator * redefinition definition to multiply strings by an integer:
  std::string operator * ( const std::string & generic_string, unsigned int integer ) 
   {
    std::string output = "";
    while ( integer -- ) 
     {
      output += generic_string;
     }
    return output;
   }

  std::string operator * ( unsigned int integer, const std::string & generic_string ) 
   {
    return generic_string * integer;
   }

  //Function to give customized runtime error:
  template <typename T>
  std::runtime_error runtime_error_func( std::string beg, T variable, std::string end )
   {
    std::string error = beg + 
                        static_cast <std::string>(" \"") + 
                        static_cast <std::string>( variable ) +
                        static_cast <std::string>( "\" " ) + 
                        end + 
                        "\n";
    return std::runtime_error( error );
   }
  
  template std::runtime_error runtime_error_func <std::string>( std::string beg, std::string variable, std::string end );

  //Function to check if an element is present in map keys:
  template <typename T, typename M>
  bool elem_in_map( T elem, std::map <T, M> map_)
   {
    for( const auto & element: map_ )
     {
      if( element.first == elem )
       {
        return true;
       }
     }
    return false;
   }

  template bool elem_in_map <std::string, std::string>( std::string elem, std::map <std::string, std::string> map_ );
  template bool elem_in_map <std::string, std::set<std::string>>( std::string elem, std::map <std::string, std::set<std::string>> map_ );
 }