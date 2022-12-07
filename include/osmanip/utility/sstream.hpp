//====================================================
//     File data
//====================================================
/**
 * @file sstream.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-11-2
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_MAIN_INCLUDE_UTILITY_SSTREAM_HPP
#define OSMANIP_MAIN_INCLUDE_UTILITY_SSTREAM_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <mutex>
#include <sstream>
#include <stdint.h>

namespace osm
{

  //====================================================
  //     Classes
  //====================================================

  // Stringbuf
  /**
   * @brief This class inherits std::stringbuf and adds additional functionality and threadsafety.
   *
   */
  class Stringbuf : public std::stringbuf
  {
    public:
    //====================================================
    //     Constructor and destructor
    //====================================================

    Stringbuf();

    // Destructor
    ~Stringbuf() override;

    //====================================================
    //     Getters
    //====================================================

    std::mutex & getMutex();

    //====================================================
    //     Virtual methods
    //====================================================

    int32_t sync() override;

    private:
    //====================================================
    //     Private attributes
    //====================================================

    std::mutex mutex_;
  };

  // Ostreambuf
  /**
   * @brief This class inherits Stringbuf and adds the ability to send output to a specific std::ostream buffer as well as redirect output to osm::redirout.
   *
   */
  class Ostreambuf : public Stringbuf
  {
    public:
    //====================================================
    //     Constructors
    //====================================================

    Ostreambuf();
    explicit Ostreambuf( std::ostream * ostream );

    //====================================================
    //     Destructor
    //====================================================

    ~Ostreambuf() override;

    //====================================================
    //     Setters
    //====================================================

    void setOstream( std::ostream * ostream );

    //====================================================
    //     Getters
    //====================================================

    std::ostream * getOstream();
    //====================================================
    //     Virtual methods
    //====================================================

    int32_t sync() override;

    private:
    //====================================================
    //     Private attributes
    //====================================================

    std::ostream * ostream_;

    //====================================================
    //     Private methods
    //====================================================

    void sync_output();
    void sync_redirection();
  };

}      // namespace osm

#endif      // OSMANIP_MAIN_INCLUDE_UTILITY_SSTREAM_HPP
