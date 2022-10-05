//====================================================
//     File data
//====================================================
/**
 * @file output_redirector.cpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 */

#include "output_redirector.h"
#include "../utils/strings.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace osm
{

  OutputRedirector::OutputRedirector():
   streambuf_backup_( nullptr ), output_stringbuf_( new std::stringbuf() )
  {
    touch();
  }

  OutputRedirector::OutputRedirector( std::string & filename ):
   filename_( filename ), streambuf_backup_( nullptr ), output_stringbuf_( new std::stringbuf() )
  {
    touch();
  }

  OutputRedirector::~OutputRedirector()
  {
    end();
    delete output_stringbuf_;
  }

  void OutputRedirector::begin()
  {
    // Back up std::cout buffer
    streambuf_backup_ = std::cout.rdbuf();

    clear_buffer();

    // Redirect output to a string stream, so we can format the data before writing to file
    std::cout.rdbuf( output_stringbuf_ );
  }

  void OutputRedirector::end()
  {
    // Redirect std::cout back to screen
    std::cout.rdbuf( streambuf_backup_ );
    flush();
  }

  // "Flush" the buffer and write to the file
  void OutputRedirector::flush()
  {
    try
    {
      redirect_output( filename_ );
    }
    catch( std::runtime_error & e )
    {
      std::cout << e.what();
    }

    // Clear the buffer before preceding.
    clear_buffer();
  }

  // Opens the file, if present. Otherwise, creates the file.
  void OutputRedirector::touch() const
  {
    if( std::ifstream existing_file( filename_ ); existing_file.is_open() )
    {
      existing_file.close();
    }
    else
    {
      if( std::ofstream new_file( filename_ ); new_file )
      {
        new_file.close();
      }
      else
      {
        file_not_found_exception();
      }
    }
  }

  void OutputRedirector::redirect_output( std::string & filename ) const
  {
    // Modify the file contents
    if( std::ifstream in_file( filename ); in_file )
    {
      // Get the file contents
      std::stringstream sstream;
      sstream << in_file.rdbuf();
      in_file.close();

      // Erase the last line of the file to make it consistent to the CLI output
      std::string contents = erase_last_line( sstream.str() );

      // Get the output string to write to the file
      std::string write_str = get_formatted_string( output_stringbuf_->str() );

      // Write buffer contents to file
      if( std::fstream out_file( filename ); out_file )
      {
        out_file << contents << write_str;
        out_file.close();
      }
      else
      {
        file_not_found_exception();
      }
    }
    else
    {
      file_not_found_exception();
    }
  }

  const std::string & OutputRedirector::get_filename() const
  {
    return filename_;
  }

  void OutputRedirector::set_filename( const std::string & filename )
  {
    filename_ = filename;
  }

  void OutputRedirector::clear_buffer()
  {
    if( !output_stringbuf_ )
    {
      output_stringbuf_ = new std::stringbuf();
    }
    output_stringbuf_->str( "" );
  }
  void OutputRedirector::file_not_found_exception() const
  {
    throw std::invalid_argument( std::string( "Could not open file " ) + "'" + filename_ + "'" );
  }

}      // namespace osm
