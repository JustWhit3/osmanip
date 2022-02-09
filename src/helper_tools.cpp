#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <type_traits>
#include <stdexcept>
#include <cmath>
#include "../include/helper_tools.hpp"
  
namespace osm
 {
  //====================================================
  //     GLOBAL VARIABLES DECLARATION
  //       (in implementation file)
  //====================================================
  std::string output, error;

  //====================================================
  //     OPERATOR * REDEFINITIONS
  // (to multiply strings by an integer)
  //====================================================
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

  //====================================================
  //     FUNCTION FOR CUSTOMIZED RUNTIME ERROR
  //====================================================
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

  //====================================================
  //     FUNCTION TO CHECK IF A CONDITION IS VERIFIED
  //     AND IN POSITIVE CASE RETURN IT
  //====================================================
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
  
  //Explicit instantiations:
  template std::string check_condition <std::string, std::string> 
  ( std::function <bool()> condition, std::string return_it, std::string return_false );

  template int check_condition <int, int> 
  ( std::function <bool()> condition, int return_it, int return_false );

  template long check_condition <long, long> 
  ( std::function <bool()> condition, long return_it, long return_false );

  template long long check_condition <long long, long long> 
  ( std::function <bool()> condition, long long return_it, long long return_false );

  template long double check_condition <long double, long double> 
  ( std::function <bool()> condition, long double return_it, long double return_false );

  template float check_condition <float, float> 
  ( std::function <bool()> condition, float return_it, float return_false );
  
  template double check_condition <double, double> 
  ( std::function <bool()> condition, double return_it, double return_false );

  //====================================================
  //     FUNCTION TO CHECK IF EXPRESSION TYPE IS
  //     FLOATING POINT
  //====================================================
  template <typename T>
  bool isFloatingPoint( const T & expression )
   {
    return std::is_floating_point <T>::value;
   }

  //Explicit instantiations:
  template bool isFloatingPoint <int> ( const int & expression );
  template bool isFloatingPoint <long> ( const long & expression );
  template bool isFloatingPoint <long long> ( const long long & expression );
  template bool isFloatingPoint <float> ( const float & expression );
  template bool isFloatingPoint <double> ( const double & expression );
  template bool isFloatingPoint <long double> ( const long double & expression );

  //====================================================
  //     FUNCTION TO ROUND A FLOATING POINT TO N 
  //     DECIMAL PLACES
  //====================================================
  template <typename T>
  extern T roundoff( const T value, const unsigned char prec )
   {
    T pow_10 = pow( 10.0f, static_cast <T> ( prec ) );
    return round( value * pow_10 ) / pow_10;
   }

  //Explicit instantiations:
  template double roundoff <double> ( const double value, const unsigned char prec );
  template long double roundoff <long double> ( const long double value, const unsigned char prec );
  template long roundoff <long> ( const long value, const unsigned char prec );
  template long long roundoff <long long> ( const long long value, const unsigned char prec );
  template float roundoff <float> ( const float value, const unsigned char prec );
  template int roundoff <int> ( const int value, const unsigned char prec );
 }