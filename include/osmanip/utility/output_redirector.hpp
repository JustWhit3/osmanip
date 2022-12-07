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
#  define OSMANIP_OUTPUTREDIRECTOR_HPP

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/utility/sstream.hpp>

// STD headers
#include <atomic>
#include <fstream>
#include <filesystem>
#include <stdint.h>
#include <string>

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
   : public std::ostream
   , public Stringbuf
  {
    public:
    //====================================================
    //     Constructors
    //====================================================

    OutputRedirector();
    explicit OutputRedirector( std::string filename );

    //====================================================
    //     Destructor
    //====================================================

    ~OutputRedirector() override;

    //====================================================
    //     Setters
    //====================================================

    void setFilename( const std::string & filename );

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
    void touch();

    bool isEnabled();

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
    std::atomic<bool> enabled_;

    std::string file_dir_;
    std::string filename_;
    std::string filepath_;

    std::fstream fstream_;
    std::stringstream output_str_;

    int32_t last_ansi_str_index_;
    int32_t last_ansi_str_size_;

    //====================================================
    //     Private methods
    //====================================================

    // Virtual
    int32_t sync() override;

    // Helpers
    void write_output();
    void prepare_output();
    void read_file();

    // Exceptions
    void sanity_check( const std::string & func_name );
    void exception_file_not_found();
  };

 }      // namespace osm

#endif