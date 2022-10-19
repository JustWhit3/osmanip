//====================================================
//     File data
//====================================================
/**
 * @file output_redirector.cpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include "../include/redirection/output_redirector.hpp"
#include "../include/utility/strings.hpp"

// STD headers
#include <iostream>
#include <sstream>
#include <utility>

namespace osm
 {
  //====================================================
  //     Constant variable
  //====================================================
  const std::string OutputRedirector::DEFAULT_FILENAME = "redirected_output.txt";
  const std::string OutputRedirector::DEFAULT_FILE_DIR = fs::current_path().string();
  const std::string OutputRedirector::DEFAULT_FILEPATH = DEFAULT_FILE_DIR + DEFAULT_FILENAME;

  //====================================================
  //     Constructors and destructors
  //====================================================

  // Default constructor
  /**
   * @brief Construct a new OutputRedirector object. Default constructor will set the main attributes to default values.
   *
   */
  OutputRedirector::OutputRedirector():
   filename_( DEFAULT_FILENAME ),
   filepath_( DEFAULT_FILEPATH ),
   output_stringbuf_( new std::stringbuf() ),
   streambuf_backup_( nullptr ),
   ref_count( 0 )
   {}

  // Parametric constructor
  /**
   * @brief Construct a new OutputRedirector object. The filename must be relative to the working directory.
   *
   * @param filename name of the output file.
   */
  OutputRedirector::OutputRedirector( std::string filename ):
   filename_( std::move( filename ) ),
   filepath_( fs::current_path() /= filename_ ),
   output_stringbuf_( new std::stringbuf() ),
   streambuf_backup_( nullptr ),
   ref_count( 0 )
   {}

  // Destructor
  /**
   * @brief Destructs OutputRedirector object.
   *
   */
  OutputRedirector::~OutputRedirector()
   {
    sanity_check( "destruction" );
    delete output_stringbuf_;
   }

  //====================================================
  //     Setters
  //====================================================

  // setFilename
  /**
   * @brief Set the filename of the output file.
   *
   * @param filename the filename of the output file.
   */
  void OutputRedirector::setFilename( const std::string & filename )
   {
    scoped_lock slock( mutex_ );
    filename_ = filename;
    filepath_ = DEFAULT_FILE_DIR + filename_;
   }

  //   void OutputRedirector::setFilepath( fs::path & path )
  //   {
  //     scoped_lock slock( mutex_ );
  //     filepath_ = path.string() + filename_;
  //   }

  //====================================================
  //     Getters
  //====================================================

  // getFilename
  /**
   * @brief Get the filename of the output file.
   *
   * @return std::string containing the filename of the output file.
   */
  std::string& OutputRedirector::getFilename()
  {
    scoped_lock slock( mutex_ );
    return filename_;
  }

  // getFilepath
  /**
   * @brief Get the name of the path to the output file.
   *
   * @return std::string containing the name of the path to the output file.
   */
  std::string& OutputRedirector::getFilepath()
  {
    scoped_lock slock( mutex_ );
    return filepath_;
  }

  //====================================================
  //     Methods
  //====================================================

  // begin
  /**
   * @brief Backs up the stdout buffer and begins redirecting output to a file
   *
   */
  void OutputRedirector::begin()
   {
    sanity_check( "begin" );
    ++ref_count;

    scoped_lock slock( mutex_ );

    streambuf_backup_ = std::cout.rdbuf();
    clear_buffer();

    // Redirect output to the output string buffer
    std::cout.rdbuf( output_stringbuf_ );
   }

  // end
  /**
   * @brief Returns output to stdout and flushes our buffer
   *
   */
  void OutputRedirector::end()
   {
    sanity_check( "end" );

     {
      scoped_lock slock( mutex_ );

      // Redirect std::cout back to screen
      std::cout.rdbuf( streambuf_backup_ );
     }
    flush();
    
    --ref_count;
   }

  // flush
  /**
   * @brief Attempts to write the new output buffer to the file, then clears the buffer.
   *
   */
  void OutputRedirector::flush()
   {
    sanity_check( "flush" );

    try
     {
      redirect_output( filename_ );
     }
    catch( std::runtime_error & e )
     {
      std::cout << e.what();
     }

    scoped_lock slock( mutex_ );
    clear_buffer();
   }

  // touch
  /**
   * @brief Opens the file, if present. Otherwise, creates the file.
   *
   */
  void OutputRedirector::touch()
   {
    lock_guard guard( mutex_ );

    if( fstream_.open( filename_, std::fstream::in ); !fstream_.is_open() )
     {
      if( fstream_.open( filename_, std::fstream::trunc | std::fstream::out ); !fstream_.is_open() )
       {
        exception_file_not_found();
       }
     }

    fstream_.close();
   }

  //====================================================
  //     Private methods
  //====================================================

  // redirect_output
  /**
   * @brief Responsible for obtaining the new file buffer, formatted output string, and writing to the file.
   *
   */
  void OutputRedirector::redirect_output( std::string & filename )
   {
    std::string output_string_fmt;
    std::string file_contents;

    touch();
    file_contents = read_file( filename );

    // Erase the last line of the file to make it consistent to the CLI output
    file_contents = erase_last_line( file_contents );

     {
      scoped_lock slock( mutex_ );
      output_string_fmt = get_formatted_string( output_stringbuf_->str() );
     }

    write_to_file( filename, file_contents + output_string_fmt );
   }

  // clear_buffer
  /**
   * @brief Sets the output string buffer to empty, or creates a new one if it is null. Due to the frequency of calls, it is required to own the mutex before calling this function.
   *
   */
  void OutputRedirector::clear_buffer()
   {
    if( ! output_stringbuf_ )
     {
      output_stringbuf_ = new std::stringbuf();
     }

    output_stringbuf_->str( "" );
   }

  // read_file
  /**
   * @brief Reads a file and returns a string of its entire contents.
   *
   * @param filename the name of the file to be read.
   *
   * @throws std::invalid_argument if unsuccessful.
   *
   * @return std::string of the file contents if successful, otherwise an empty string.
   */
  std::string OutputRedirector::read_file( const std::string & filename )
   {
    std::stringstream sstream;
    scoped_lock slock( mutex_ );

    if( fstream_.open( filename, std::fstream::in ); fstream_.is_open() )
     {
      sstream << fstream_.rdbuf();
      fstream_.close();

      return sstream.str();
     }
    else
     {
      exception_file_not_found();
     }

    return "";
   }

  // write_to_file
  /**
   * @brief Writes a string to a file. The file will be cleared before the string is written.
   *
   * @param filename the name of the file to be written.
   * @param out_string the string to be written to the file.
   *
   * @throws std::invalid_argument if unsuccessful.
   *
   * @return true if successful, otherwise, false.
   */
  bool OutputRedirector::write_to_file( const std::string & filename, const std::string & out_string )
   {
    scoped_lock slock( mutex_ );

    if( fstream_.open( filename, std::fstream::trunc | std::fstream::out ); !fstream_.is_open() )
     {
      exception_file_not_found();
      return false;
     }

    fstream_ << out_string;
    fstream_.close();

    return true;
   }

  // sanity_check
  /**
   * @brief Asserts the reference counter is correct for the specified function.
   *
   * @throw std::runtime_error if the reference counter is incorrect.
   * @throws std::invalid_argument if an unknown function name is used.
   */
  void OutputRedirector::sanity_check( const std::string & func_name )
   {
    if( func_name == "begin" || func_name == "destruction")
     {
      if( ref_count != 0 )
       {
        throw std::runtime_error( "Did you forget to call 'end()'?" );
       }
     }
    else if( func_name == "end" || func_name == "flush" )
     {
      if( ref_count != 1 )
       {
        throw std::runtime_error( "Did you forget to call 'begin()'?" );
       }
     }
    else
     {
      throw std::invalid_argument( "Unknown function name." );
     }
   }

  // exception_file_not_found
  /**
   * @brief Throws an std::invalid_argument error if the file was not found or could not be opened. It is important to note that the calling thread is excepted to own the mutex. Calling this function will retain ownership of the mutex and release it before throwing the exception.
   *
   * @throws std::invalid_argument
   */
  void OutputRedirector::exception_file_not_found()
   {
     {
      mutex_.try_lock();
      lock_guard guard( mutex_, std::adopt_lock );
     }

    throw std::invalid_argument( std::string( "Could not open file " ) + "'" + filename_ + "'" );
   }
 }