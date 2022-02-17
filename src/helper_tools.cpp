#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <type_traits>
#include <stdexcept>
#include <cmath>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>

#include "../include/helper_tools.hpp"

#define ARGS( ... ) BOOST_PP_TUPLE_TO_SEQ( ( __VA_ARGS__ ) )
  
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

  //Explicit instantiations:
  #define RUNTIME_ERROR_FUNC( r, data, T ) template \
  std::runtime_error runtime_error_func <T> ( std::string beg, T variable, std::string end );

  BOOST_PP_SEQ_FOR_EACH( RUNTIME_ERROR_FUNC, _, ARGS( std::string ) );

  //====================================================
  //     FUNCTION TO CHECK IF A CONDITION IS VERIFIED
  //     AND IN POSITIVE CASE RETURN IT
  //====================================================
  template <typename T>
  T check_condition( std::function <bool()> condition, T return_it, T return_false )
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
  #define CHECK_CONDITION( r, data, T ) template \
  T check_condition <T> ( std::function <bool()> condition, T return_it, T return_false );

  BOOST_PP_SEQ_FOR_EACH( CHECK_CONDITION, _, ARGS( int, long, long long, long double, float, double, std::string ) );

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
  #define ISFLOATINGPOINT( r, data, T ) template \
  bool isFloatingPoint <T> ( const T & expression );

  BOOST_PP_SEQ_FOR_EACH( ISFLOATINGPOINT, _, ARGS( int, long, long long, float, double, long double ) );

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
  #define ROUNDOFF( r, data, T ) template \
  T roundoff <T> ( const T value, const unsigned char prec  );

  BOOST_PP_SEQ_FOR_EACH( ROUNDOFF, _, ARGS( int, double, long double, long, long long, float ) );
 }