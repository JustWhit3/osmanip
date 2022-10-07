//====================================================
//     File data
//====================================================
/**
 * @file strings.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_STRINGS_HPP
#define OSMANIP_STRINGS_HPP
#endif

//====================================================
//     Headers
//====================================================

// STD headers
#include <string>

namespace osm
{

  // find_first_alpha
  /**
   * @brief Finds the index of the first alphabetic character in the string, starting from the given position.
   *
   * @param pos the starting position.
   * @param string the string to be searched.
   *
   * @return size_t of the index if successful, otherwise std::string::npos.
   */
  size_t find_first_alpha( size_t pos, const std::string & string )
  {
    for( size_t i = pos; i < string.size(); ++i )
    {
      if( std::isalpha( static_cast<unsigned char>( string[ i ] ) ) )
      {
        return i;
      }
    }
    return std::string::npos;
  }

  // get_formatted_string
  /**
   * @brief Gets a copy of the given string with all ANSI escape sequences removed.
   *
   * @param string the string to be formatted.
   *
   * @return std::string copy without ANSI escape sequences.
   */
  std::string get_formatted_string( const std::string & string )
  {
    std::string result = string;

    for( size_t i = 0; i < result.size(); ++i )
    {
      if( size_t esc_pos = result.find( "\u001b[", i ); esc_pos != std::string::npos )
      {
        size_t bracket_pos = esc_pos + 1;
        if( size_t alpha_pos = find_first_alpha( bracket_pos + 1, result ); alpha_pos != std::string::npos )
        {
          // We want the range from the char after the bracket and the alpha inclusive, so we add one to each position
          result.erase( esc_pos, alpha_pos - bracket_pos + 2 );
          i = ( int )esc_pos - 1;
        }
      }
    }

    return result;
  }

  // erase_last_line
  /**
   * @brief Checks for an endline starting from the end of the given string and returns a string. If no endline is found, a copy of the string is returned. Otherwise, a copy of the given string is returned with the last line erased up to the first endline found.
   *
   * @param string the string to be searched.
   *
   * @return std::string substring with the last line erased or a copy if an endline is not found.
   */
  static std::string erase_last_line( const std::string & string )
  {
    if( auto it = string.rfind( '\n', string.size() - 1 ); it != std::string::npos )
    {
      std::string result = string;
      result.erase( it + 1 );
      return result;
    }
    return string;
  }

}      // namespace osm