#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <type_traits>
#include "../include/helper_tools.h"
  
namespace osm
 {
  //Global variables declaration in implementation file:
  std::string output, error;

  //Operator * redefinitions to multiply strings by an integer:
  std::string operator * ( const std::string & generic_string, unsigned int integer ) 
   {
    output = "";
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
    error = beg + 
            static_cast <std::string>(" \"") + 
            static_cast <std::string>( variable ) +
            static_cast <std::string>( "\" " ) + 
            end + 
            "\n";
    return std::runtime_error( error );
   }
  
  template std::runtime_error runtime_error_func <std::string>
  ( std::string beg, std::string variable, std::string end );

  //Function to check if a given condition is verified or not and in positive case return it:
  template <typename T, typename R>
  T check_condition( std::function <bool()> condition, T return_it, R return_false)
   {
    if( condition() )
     {
      return return_it;
     }
    else
     {
      return return_false;
     }
   }
  
  template std::string check_condition <std::string, std::string> 
  ( std::function <bool()> condition, std::string return_it, std::string return_false );

  //Function to check if expression type is floating point:
  template <typename T>
  bool isFloatingPoint( const T & expression )
   {
    return std::is_floating_point <T>::value;
   }

  template bool isFloatingPoint <int> ( const int & expression );
  template bool isFloatingPoint <long> ( const long & expression );
  template bool isFloatingPoint <long long> ( const long long & expression );
  template bool isFloatingPoint <float> ( const float & expression );
  template bool isFloatingPoint <double> ( const double & expression );
  template bool isFloatingPoint <long double> ( const long double & expression );
 }