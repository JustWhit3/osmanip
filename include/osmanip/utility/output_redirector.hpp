//====================================================
//     File data
//====================================================
/**
 * @file output_redirector.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
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

// My headers
#include <osmanip/utility/sstream.hpp>

// STD headers
#include <stdint.h>

#include <atomic>
#include <filesystem>
#include <fstream>
#include <string>

namespace osm {

    //====================================================
    //     Aliases
    //====================================================
    namespace fs = std::filesystem;

    //====================================================
    //     OutputRedirector
    //====================================================
    /**
     * @brief This class is used to redirected
     * output to a file.
     *
     */
    class OutputRedirector : public std::ostream, public Stringbuf {
        public:

            // Constructors and destructor
            OutputRedirector();
            explicit OutputRedirector(std::string filename);
            ~OutputRedirector() override;

            // Setters
            void setFilename(std::string_view filename);

            // Getters
            [[nodiscard]] std::string &getFilename();
            [[nodiscard]] std::string &getFilepath();

            // Methods
            void end();
            void begin();
            void touch();
            bool isEnabled();

            // Members
            static const std::string DEFAULT_FILE_DIR;
            static const std::string DEFAULT_FILEPATH;
            static const std::string DEFAULT_FILENAME;

        private:

            // Methods
            int32_t sync() override;
            void write_output();
            void prepare_output();
            void read_file();
            void sanity_check(const std::string &func_name);
            void exception_file_not_found();

            // Members
            std::atomic<bool> enabled_;
            std::string file_dir_;
            std::string filename_;
            std::string filepath_;
            std::fstream fstream_;
            std::stringstream output_str_;
            int32_t last_ansi_str_index_;
            int32_t last_ansi_str_size_;
    };

}  // namespace osm

#endif