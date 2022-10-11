//====================================================
//     File data
//====================================================
/**
 * @file output_redirector.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_OUTPUTREDIRECTOR_HPP
#  define OSMANIP_OUTPUTREDIRECTOR_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#  include <mutex>
#  include <string>
#  include <fstream>
#  include <streambuf>
#  include <filesystem>
#  include <atomic>

namespace osm
{
  //====================================================
  //     Aliases
  //====================================================
  namespace fs = std::filesystem;

  //====================================================
  //     Classes
  //====================================================

  // OutputRedirector
  /**
   * @brief This class is used to redirected output to a file.
   *
   */
  class OutputRedirector
  {
    typedef std::scoped_lock<std::mutex> scoped_lock;
    typedef std::lock_guard<std::mutex> lock_guard;

    public:
    //====================================================
    //     Constructors
    //====================================================
    OutputRedirector();
    explicit OutputRedirector( std::string filename );

    //====================================================
    //     Destructor
    //====================================================
    ~OutputRedirector();

    //====================================================
    //     Setters
    //====================================================
    void setFilename( const std::string & filename );
    //     void setFilepath( fs::path & path );

    //====================================================
    //     Getters
    //====================================================
    [[nodiscard]] std::string & getFilename();
    [[nodiscard]] std::string & getFilepath();

    //====================================================
    //     Methods
    //====================================================
    void end();
    void begin();
    void flush();
    void touch();

    //====================================================
    //     Static public variable
    //====================================================
    static const std::string DEFAULT_FILE_DIR;
    static const std::string DEFAULT_FILEPATH;
    static const std::string DEFAULT_FILENAME;

    private:
    //====================================================
    //     Private attributes
    //====================================================
    std::mutex mutex_;
    std::atomic<int32_t> ref_count;

    std::string file_dir_;
    std::string filename_;
    std::string filepath_;

    std::fstream fstream_;
    std::stringbuf * output_stringbuf_;
    std::streambuf * streambuf_backup_;

    //====================================================
    //     Private methods
    //====================================================
    void clear_buffer();
    void redirect_output( std::string & filename );

    // File
    std::string read_file( const std::string & filename );
    bool write_to_file( const std::string & filename, const std::string & out_string );

    // Exceptions
    void sanity_check( const std::string & func_name );
    void exception_file_not_found();
  };

}      // namespace osm

#endif