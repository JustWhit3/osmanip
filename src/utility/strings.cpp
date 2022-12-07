//====================================================
//     File data
//====================================================
/**
 * @file strings.cpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include <utility/strings.hpp>
#include <utility/iostream.hpp>

// STD headers
#include <stdexcept>
#include <stdio.h>
#include <cctype>

namespace osm
{

  //====================================================
  //     Functions
  //====================================================

  /**
   * @brief Removes all leading and trailing spaces from a string.
   *
   * @param str the string to be trimmed.
   *
   * @return string with no leading or tailing spaces.
   *
   */
  std::string trim_string( const std::string & str )
  {
    if( str.empty() )
    {
      return str;
    }

    std::string res = str;
    size_t first = 0, last = res.size() - 1;

    if( res.front() == ' ' )
    {
      first = res.find_first_not_of( ' ' );
    }

    while( last > first && res.at( last-- ) == ' ' )
    {
      --last;
    }

    res = last + 1 == std::string::npos ? res.substr( first )
                                        : res.substr( first, ( last + 1 ) - first );
    return res;
  }

  // find_first_alpha
  /**
   * @brief Finds the index of the first alphabetic character in the str, starting from the given position.
   *
   * @param str the string be searched.
   * @param pos the starting position.
   *
   * @return the index of the alpha char if successful, otherwise std::string::npos.
   *
   */
  [[maybe_unused]] size_t find_first_alpha( const std::string & str, size_t pos )
  {
    for( size_t i = pos; i < str.size(); ++i )
    {
      if( std::isalpha( static_cast<unsigned char>( str[ i ] ) ) )
      {
        return i;
      }
    }
    return std::string::npos;
  }

  // get_formatted_from_ansi
  /**
   * @brief Formats a string according to the ANSI (Control Sequence Introducer) escape sequences present within the string. Can be used in a loop with appending data by using optional arguments.
   *
   * @param str the string to be formatted.
   * @param last_pos [Optional] the final position (index) of the last string to be formatted.
   * @param last_size [Optional] the size of the last string to be formatted.
   *
   * @return a correctly formatted string, free of any ANSI escape sequences.
   *
   */
  std::string get_formatted_from_ansi( const std::string & str, int32_t * last_pos, int32_t * last_size )
  {
    int32_t dst_crsr_pos = last_pos ? *last_pos : 0;
    int32_t last_dst_str_len = last_size ? *last_size : 0;
    int32_t src_crsr_pos = 0;

    std::string res;
    res.reserve( str.size() );

    std::string ch;
    ch.reserve( 1 );

    // Get the most recently formatted string (if available)
    if( last_dst_str_len > 0 && ( int32_t )str.size() >= last_dst_str_len )
    {
      res = str.substr( 0, last_dst_str_len );
      src_crsr_pos = last_dst_str_len;
    }

    for( ; src_crsr_pos < ( int32_t )str.size(); ++src_crsr_pos )
    {
      ch = str.at( src_crsr_pos );

      if( ch.front() == '\033' )
      {
        // Extract the ansi escape sequence from str and move past it
        std::string csi_str = get_ansi_csi_string( str, src_crsr_pos );

        // Not a complete CSI
        if( csi_str.empty() )
        {
          if( src_crsr_pos + 1 < ( int32_t )str.size() && str.at( src_crsr_pos + 1 ) == '[' )
          {
            // Move past the bracket
            src_crsr_pos += 2;
          }
          else
          {
            // Move past the ESC
            src_crsr_pos += 1;
          }
        }
        else
        {
          // Move past the CSI and handle it in the res string
          src_crsr_pos += ( int32_t )csi_str.size();
          handle_csi( csi_str, res, &dst_crsr_pos );
        }

        --src_crsr_pos;
      }
      else
      {
        if( ch.front() == '\n' || dst_crsr_pos >= ( int32_t )res.size() )
        {
          res += ch;
          dst_crsr_pos = ( int32_t )res.size();
        }
        else
        {
          // We don't want to overwrite the new line, so we insert it instead of replacing it
          if( res.at( dst_crsr_pos ) == '\n' )
          {
            res.insert( dst_crsr_pos, ch );
          }
          else
          {
            res.replace( dst_crsr_pos, 1, ch );
          }

          ++dst_crsr_pos;
        }
      }
    }

    if( last_pos )
    {
      *last_pos = dst_crsr_pos;
    }
    if( last_size )
    {
      *last_size = ( int32_t )res.size();
    }

    res.shrink_to_fit();

    return res;
  }

  // get_ansi_csi_string
  /**
   * @brief Returns the ANSI CSI (Control Sequence Introducer) in the string beginning at the given position (if present).
   *
   * @example   | 'ESC' | '[' | 'n' |  'code'  |
   *
   * @param str the string containing the ANSI CSI.
   * @param esc_pos the index of the escape_sequence in the string.
   *
   * @return a string of the ANSI CSI if found, otherwise an empty string.
   *
   */
  [[maybe_unused]] std::string get_ansi_csi_string( const std::string & str, size_t esc_pos )
  {
    if( str.at( esc_pos ) != '\033' )
    {
      return {};
    }

    return str.substr( esc_pos, find_first_alpha( str, esc_pos + 2 ) - esc_pos + 1 );
  }

  // get_ansi_csi_number
  /**
   * @brief Returns the number (n) of the ANSI CSI (Control Sequence Introducer) string.
   *
   * @example   | 'ESC' | '[' | 'n' |  'code'  |
   *
   * @param csi the ANSI CSI string.
   *
   * @throws std::invalid_argument if the string is not an ANSI CSI.
   *
   * @return the number of the ANSI CSI if found.
   *
   */
  [[maybe_unused]] int32_t get_ansi_csi_number( const std::string & csi )
  {
    const size_t n_pos = 2;

    int32_t number = -1;

    if( n_pos < csi.size() )
    {
      // Verify the value after the bracket is actually a number
      if( !std::isdigit( csi.at( n_pos ) ) )
      {
        char error_msg[ 32 ];
        sprintf( error_msg, "%hhd is not a valid digit!", csi.at( n_pos ) );
        throw std::invalid_argument( error_msg );
      }

      if( size_t alpha_pos = find_first_alpha( csi, n_pos ); alpha_pos != std::string::npos )
      {
        try
        {
          number = std::stoi( csi.substr( n_pos, alpha_pos - n_pos ), nullptr );
        }
        catch( std::invalid_argument const & e )
        {
          osm::cout << e.what() << '\n';
        }
      }
    }
    return number;
  }

  // get_ansi_csi_code
  /**
   * @brief Returns the command code of the ANSI CSI (Control Sequence Introducer) string.
   *
   * @example   | 'ESC' | '[' | 'n' |  'code'  |
   *
   * @param csi the ANSI CSI string.
   *
   * @throws std::invalid_argument if the string is not an ANSI CSI.
   *
   * @return the code of the ANSI CSI if found. Otherwise, returns a null terminator.
   *
   */
  [[maybe_unused]] char get_ansi_csi_code( const std::string & csi )
  {
    const size_t n_pos = 2;

    if( n_pos < csi.size() )
    {
      // Verify the value after the bracket is actually a number
      if( !std::isdigit( csi.at( n_pos ) ) )
      {
        char error_msg[ 32 ];
        sprintf( error_msg, "%hhd is not a valid digit!", csi.at( n_pos ) );
        throw std::invalid_argument( error_msg );
      }

      if( size_t alpha_pos = find_first_alpha( csi, n_pos ); alpha_pos != std::string::npos )
      {
        return csi.at( alpha_pos );
      }
    }
    return '\0';
  }

  // handle_csi
  /**
   * @brief Given a string of an ANSI CSI (Control Sequence Introducer), this function will execute the CSI and correctly modify the destination string and update the current position.
   *
   * @cite Documentation from https://en.wikipedia.org/wiki/ANSI_escape_code
   *
   * @param csi_str a string of the ANSI CSI
   * @param dst_str the destination string to modify
   * @param dst_crsr_pos the current position (index) of the destination string
   *
   */
  [[maybe_unused]] void handle_csi( const std::string & csi_str, std::string & dst_str, int32_t * dst_crsr_pos )
  {
    int32_t number;
    try
    {
      number = get_ansi_csi_number( csi_str );
    }
    catch( std::invalid_argument & e )
    {
      osm::cout << "Error: " << e.what() << "\n";
      return;
    }

    char code = get_ansi_csi_code( csi_str );

    int32_t curr_pos = *dst_crsr_pos < ( int32_t )dst_str.size() ? *dst_crsr_pos : ( int32_t )dst_str.size();
    int32_t starting_pos = 0;
    int32_t line_len = 0;
    bool first_line = true;

    // Handle the sequence
    switch( code )
    {
        /**
         * @brief Moves the cursor n (default 1) cells in the given direction.
         * If the cursor is already at the edge of the screen, this has no effect.
         *
         * @examples ESC[nA, ESC[nB, ESC[nC, ESC[nD
         *
         */
      case 'A':
      {
        for( size_t line_count = 0; (int32_t)line_count < number; ++line_count )
        {
          for( ; curr_pos - 1 >= 0; --curr_pos, ++line_len )
          {
            if( char ch = dst_str.at( curr_pos - 1 ); ch == '\n' )
            {
              if( first_line )
              {
                starting_pos = line_len;
                first_line = false;
              }
              --curr_pos;
              break;
            }
          }
          line_len = 0;
        }

        if( curr_pos < 0 )
        {
          *dst_crsr_pos = 0;
        }
        else
        {
          for( int32_t prev_pos = curr_pos - 1; prev_pos >= 0; --prev_pos, ++line_len )
          {
            if( dst_str.at( prev_pos ) == '\n' )
            {
              break;
            }
          }

          if( starting_pos < line_len )
          {
            *dst_crsr_pos = curr_pos - line_len + starting_pos;
          }
          else
          {
            *dst_crsr_pos = curr_pos;
          }
        }
        break;
      }
      case 'B':
      {
        for( size_t line_count = 0; (int32_t)line_count < number; ++line_count )
        {
          for( ; curr_pos >= 0 && curr_pos < ( int32_t )dst_str.size(); ++curr_pos, ++line_len )
          {
            if( char ch = dst_str.at( curr_pos ); ch == '\n' )
            {
              if( first_line )
              {
                // Get the original position of the cursor on the line
                int32_t prev_pos = curr_pos - line_len - 1;
                for( ; prev_pos >= 0; --prev_pos, ++line_len )
                {
                  if( dst_str.at( prev_pos ) == '\n' )
                  {
                    break;
                  }
                }

                starting_pos = line_len;
                first_line = false;
              }

              ++curr_pos;
              break;
            }
          }

          line_len = 0;
        }

        if( curr_pos >= (int32_t)dst_str.size() )
        {
          *dst_crsr_pos = ( int32_t )dst_str.size();
        }
        else
        {
          // Get the length of the current line
          for( int32_t next_pos = curr_pos; next_pos < ( int32_t )dst_str.size(); ++next_pos, ++line_len )
          {
            if( dst_str.at( next_pos ) == '\n' )
            {
              break;
            }
          }

          if( starting_pos > line_len )
          {
            *dst_crsr_pos = curr_pos + line_len;
          }
          else
          {
            *dst_crsr_pos = curr_pos + starting_pos;
          }
        }
        break;
      }
      case 'C':
      {
        // TODO: Implement right movement
        break;
      }
      case 'D':
      {
        // "ESC[100D" is not always enough to return to the edge of the screen, so guarantee it by increasing the number
        number = ( number == 100 ) ? ( int32_t )dst_str.size() : number;

        for( int32_t prev_pos = curr_pos - 1; prev_pos >= 0 && line_len < number; --prev_pos, ++line_len )
        {
          if( dst_str.at( prev_pos ) == '\n' )
          {
            break;
          }
        }

        if( line_len > 0 )
        {
          *dst_crsr_pos = curr_pos - line_len;
        }
        else
        {
          *dst_crsr_pos = curr_pos;
        }
        break;
      }
        /**
         * @brief If n is 0 (or missing), clear from cursor to end of screen. If n is 1, clear from cursor to beginning of the screen. If n is 2 or 3, clear entire screen.
         *
         * @example ESC[nJ
         *
         */
      case 'J':
      {
        // TODO: Implement clear screen
        //  Implement number == 0
        //  Implement number == 1
        //  Implement number == 2
        //  Implement number == 3

        break;
      }
        /**
         * @brief If n is 0 (or missing), clear from cursor to the end of the line. If n is 1, clear from cursor to beginning of the line. If n is 2, clear entire line. Cursor position does not change.
         *
         * @example ESC[nK
         *
         */
      case 'K':
      {
        if( number == 0 )
        {
          for( ; curr_pos < (int32_t)dst_str.size(); ++curr_pos, ++line_len )
          {
            if( char ch = dst_str.at( curr_pos ); ch == '\n' )
            {
              break;
            }
          }

          dst_str.erase( *dst_crsr_pos, line_len );
        }

        // TODO:
        //  Implement number == 1
        //  Implement number == 2`
        break;
      }
      default:;
    }
  }

}      // namespace osm