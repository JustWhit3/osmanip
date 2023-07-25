//====================================================
//     File data
//====================================================
/**
 * @file sstream.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-11-2
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_UTILITY_SSTREAM_HPP
#define OSMANIP_UTILITY_SSTREAM_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <stdint.h>

#include <mutex>
#include <sstream>

namespace osm {

    //====================================================
    //     Stringbuf
    //====================================================
    /**
     * @brief This class inherits std::stringbuf
     * and adds additional functionality and
     * thread safety.
     *
     */
    class Stringbuf : public std::stringbuf {
        public:

            // Constructors and destructor
            Stringbuf();
            ~Stringbuf() override;

            // Getters
            std::mutex &getMutex();

            // Methods
            int32_t sync() override;

        private:

            // Attributes
            std::mutex mutex_;
    };

    //====================================================
    //     Ostreambuf
    //====================================================
    /**
     * @brief This class inherits Stringbuf and
     * adds the ability to send output to a
     * specific std::ostream buffer as well as
     * redirect output to osm::redirout.
     *
     */
    class Ostreambuf : public Stringbuf {
        public:

            // Constructors and destructor
            Ostreambuf();
            explicit Ostreambuf(std::ostream *ostream);
            ~Ostreambuf() override;

            // Setters
            void setOstream(std::ostream *ostream);

            // Getters
            std::ostream *getOstream();

            // Methods
            int32_t sync() override;

        private:

            // Methods
            void sync_output();
            void sync_redirection();

            // Members
            std::ostream *ostream_;
    };

}  // namespace osm

#endif  // OSMANIP_MAIN_INCLUDE_UTILITY_SSTREAM_HPP
