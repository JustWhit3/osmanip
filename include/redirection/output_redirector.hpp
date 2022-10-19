//====================================================
//     File data
//====================================================
/**
 * @file output_redirector.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_OUTPUTREDIRECTOR_HPP
#define OSMANIP_OUTPUTREDIRECTOR_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <mutex>
#include <string>
#include <fstream>
#include <atomic>
#include <stdint.h>

// Procedure for experimental header
#ifndef __APPLE__
  #if defined( __GNUC__ ) && ( __GNUC___ <= 8 )
    #include <experimental/filesystem>
  #else
    #include <filesystem>
  #endif
#else
  #include <filesystem>
#endif

namespace osm
 {
  //====================================================
  //     Aliases
  //====================================================
  #ifndef __APPLE__
    #if defined( __GNUC__ ) && ( __GNUC___ <= 8 )
      namespace fs = std::experimental::filesystem;
    #else
      namespace fs = std::filesystem;
    #endif
  #else
      namespace fs = std::filesystem;
  #endif

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
     void setFilename( const std::string& filename );
 
     //====================================================
     //     Getters
     //====================================================
     [[nodiscard]] std::string& getFilename();
     [[nodiscard]] std::string& getFilepath();
 
     //====================================================
     //     Methods
     //====================================================
     void end();
     void begin();
     void flush();
     void touch();
 
     //====================================================
     //     Static public variables
     //====================================================
     static const std::string DEFAULT_FILE_DIR;
     static const std::string DEFAULT_FILEPATH;
     static const std::string DEFAULT_FILENAME;
 
    private:

     //====================================================
     //     Private attributes
     //====================================================
     std::mutex mutex_;
     std::atomic <int32_t> ref_count;
 
     std::string file_dir_;
     std::string filename_;
     std::string filepath_;
 
     std::fstream fstream_;
     std::stringbuf* output_stringbuf_;
     std::streambuf* streambuf_backup_;
 
     //====================================================
     //     Private methods
     //====================================================

     // General
     void clear_buffer();
     void redirect_output( std::string & filename );
 
     // File
     std::string read_file( const std::string & filename );
     bool write_to_file( const std::string & filename, const std::string & out_string );
 
     // Exceptions
     void sanity_check( const std::string & func_name );
     void exception_file_not_found();
   };
 }

#endif