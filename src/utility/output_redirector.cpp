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
#include <utility/output_redirector.hpp>
#include <utility/iostream.hpp>
#include <utility/strings.hpp>
#include <utility/sstream.hpp>

// External headers
#include <arsenalgear/utils.hpp>

// STD headers
#include <stdexcept>
#include <mutex>
#include <filesystem>
#include <sstream>
#include <utility>

namespace osm
{

//   OutputRedirector redirout;

  //====================================================
  //     Constant variables
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
   std::ostream( this ),
   Stringbuf(),
   enabled_( false ),
   filename_( DEFAULT_FILENAME ),
   filepath_( DEFAULT_FILEPATH ),
   last_ansi_str_size_( 0 ),
   last_ansi_str_index_( 0 )
  {
  }

  // Parametric constructor
  /**
   * @brief Construct a new OutputRedirector object. The filename must be relative to the working directory.
   *
   * @param filename name of the output file.
   *
   */
  OutputRedirector::OutputRedirector( std::string filename ):
   enabled_( false ),
   filename_( std::move( filename ) ),
   filepath_( fs::current_path() /= filename_ ),
   last_ansi_str_size_( 0 ),
   last_ansi_str_index_( 0 )
  {
  }

  // Destructor
  /**
   * @brief Destructs OutputRedirector object. If redirection is still enabled, the buffer is flushed before being destroyed.
   *
   */
  OutputRedirector::~OutputRedirector()
  {
    if( enabled_ )
    {
      this->flush();
      enabled_ = false;
    }
  }

  //====================================================
  //     Setters
  //====================================================

  // setFilename
  /**
   * @brief Set the filename of the output file. The filename must be relative to the working directory.
   *
   * @param filename the filename of the output file.
   *
   */
  void OutputRedirector::setFilename( const std::string & filename )
  {
    std::scoped_lock<std::mutex> slock { this->getMutex() };
    filename_ = filename;
    filepath_ = DEFAULT_FILE_DIR + filename_;

    output_str_.clear();
    last_ansi_str_index_ = 0;
    last_ansi_str_size_ = 0;
  }

  //   void OutputRedirector::setFilepath( fs::path & path )
  //   {
  //     std::scoped_lock<std::mutex> slockthis->{ getMutex() };
  //     filepath_ = path.string() + filename_;
  //   }

  //====================================================
  //     Getters
  //====================================================

  // getFilename
  /**
   * @brief Get the filename of the output file.
   *
   * @return string containing the filename of the output file.
   *
   */
  std::string & OutputRedirector::getFilename()
  {
    std::scoped_lock<std::mutex> slock { this->getMutex() };
    return filename_;
  }

  // getFilepath
  /**
   * @brief Get the name of the path to the output file.
   *
   * @return string containing the name of the path to the output file.
   *
   */
  std::string & OutputRedirector::getFilepath()
  {
    std::scoped_lock<std::mutex> slock { this->getMutex() };
    return filepath_;
  }

  //====================================================
  //     Methods
  //====================================================

  // begin
  /**
   * @brief Enables output redirection
   *
   * @throws std::runtime_error if redirection is already enabled.
   *
   */
  void OutputRedirector::begin()
  {
    sanity_check( "begin" );
    enabled_ = true;
  }

  // end
  /**
   * @brief Flushes the buffer and disables output redirection.
   *
   * @throws std::runtime_error if redirection is currently not enabled.
   *
   */
  void OutputRedirector::end()
  {
    sanity_check( "end" );
    cout.flush();
    enabled_ = false;
  }

  // touch
  /**
   * @brief Opens the file, if present. Otherwise, creates the file.
   *
   * @throws std::invalid_argument if the file cannot be opened.
   *
   */
  void OutputRedirector::touch()
  {
    std::scoped_lock<std::mutex> slock { this->getMutex() };

    if( fstream_.open( filename_, std::fstream::in ); !fstream_.is_open() )
    {
      if( fstream_.open( filename_, std::fstream::trunc | std::fstream::out ); !fstream_.is_open() )
      {
        exception_file_not_found();
      }
    }

    fstream_.close();
  }

  // isEnabled
  /**
   * @brief Returns the current state of the output redirection object.
   *
   * @return true if enabled. Otherwise, returns false.
   *
   */
  bool OutputRedirector::isEnabled()
  {
    return enabled_;
  }

  //====================================================
  //     Private methods
  //====================================================

  // sync
  /**
   * @brief Responsible for calling the appropriate output update functions and writing the result to the file.
   *
   * @return the error state of the stream buffer
   *
   */
  int32_t OutputRedirector::sync()
  {
    // Verify file is available
    touch();

    std::scoped_lock<std::mutex> slock { this->getMutex() };

    read_file();
    prepare_output();
    write_output();

    return fstream_.rdstate();
  }

  // prepare_output
  /**
   * @brief Updates and formats the output string and clears the buffer.
   *
   */
  void OutputRedirector::prepare_output()
  {
    output_str_ << this << std::flush;

    if( agr::is_escape( this->str(), agr::ANSI::generic ) )
    {
      output_str_.str( get_formatted_from_ansi( output_str_.str(), &last_ansi_str_index_, &last_ansi_str_size_ ) );
    }
    this->str( "" );
  }

  // write_output
  /**
   * @brief Writes the output string to the file. The file will be cleared before the string is written.
   *
   * @throws std::invalid_argument if there is a problem opening the file.
   *
   */
  void OutputRedirector::write_output()
  {
    if( fstream_.open( filename_, std::fstream::trunc | std::fstream::out ); !fstream_.is_open() )
    {
      exception_file_not_found();
      return;
    }

    fstream_ << output_str_.rdbuf() << std::flush;
    fstream_.close();
  }

  // read_file
  /**
   * @brief Reads the file and stores its entire contents.
   *
   * @throws std::invalid_argument if there is a problem opening the file.
   *
   */
  void OutputRedirector::read_file()
  {
    if( fstream_.open( filename_, std::fstream::in ); !fstream_.is_open() )
    {
      exception_file_not_found();
      return;
    }
    else
    {
      output_str_.str( "" );
      fstream_ >> output_str_.rdbuf();
      fstream_.close();
    }
  }

  // sanity_check
  /**
   * @brief Asserts the redirection flag is correct for the specified function.
   *
   * @throws std::runtime_error if the flag is incorrect.
   * @throws std::invalid_argument if an unknown function name is used.
   *
   */
  void OutputRedirector::sanity_check( const std::string & func_name )
  {
    if( func_name == "begin" )
    {
      if( enabled_ )
      {
        throw std::runtime_error( "Did you forget to call 'end()'?" );
      }
    }
    else if( func_name == "end" )
    {
      if( !enabled_ )
      {
        throw std::runtime_error( "Did you forget to call 'begin()'?" );
      }
    }
  }

  // exception_file_not_found
  /**
   * @brief Throws an invalid_argument exception if the file was not found or could not be opened. It is important to note that the calling thread is excepted to own the mutex. Calling this function will retain ownership of the mutex and release it before throwing the exception.
   *
   * @throws std::invalid_argument
   *
   */
  void OutputRedirector::exception_file_not_found()
  {
    std::string filename;
    {
      std::scoped_lock<std::mutex> slock { std::adopt_lock, this->getMutex() };
      filename = filename_;
    }

    throw std::invalid_argument( std::string( "Could not open file " ) + "'" + filename + "'" );
  }

}      // namespace osm