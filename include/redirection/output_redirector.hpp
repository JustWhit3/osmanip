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
#endif

//====================================================
//     Headers
//====================================================

// STD headers
#include <mutex>
#include <string>
#include <fstream>
#include <streambuf>

namespace osm
{
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
    explicit OutputRedirector( std::string & filename );

    //====================================================
    //     Destructor
    //====================================================
    ~OutputRedirector();

    //====================================================
    //     Setters
    //====================================================
    void setFilename( const std::string & filename );

    //====================================================
    //     Getters
    //====================================================
    [[nodiscard]] std::string & getFilename();

    //====================================================
    //     Methods
    //====================================================
    void end();
    void begin();
    void flush();
    void touch();

    private:
    //====================================================
    //     Private attributes
    //====================================================
    std::mutex mutex_;
    std::string filename_;
    std::fstream fstream_;
    std::stringbuf * output_stringbuf_;
    std::streambuf * streambuf_backup_;

    //====================================================
    //     Private methods
    //====================================================
    void clear_buffer();
    void redirect_output( std::string & filename );
    void exception_file_not_found();
  };

}      // namespace osm
