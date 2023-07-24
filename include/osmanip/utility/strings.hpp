//====================================================
//     File data
//====================================================
/**
 * @file strings.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_STRINGS_HPP
#define OSMANIP_STRINGS_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <stdint.h>

#include <string>

namespace osm {

    //====================================================
    //     Functions
    //====================================================

    extern std::string get_formatted_from_ansi(const std::string& str,
                                               int32_t* last_pos = nullptr,
                                               int32_t* last_size = nullptr);
    [[maybe_unused]] extern std::string trim_string(std::string& str);
    [[maybe_unused]] extern size_t find_first_alpha(std::string_view str,
                                                    size_t pos);
    [[maybe_unused]] extern std::string get_ansi_csi_string(
        const std::string& str, size_t esc_pos);
    [[maybe_unused]] extern int32_t get_ansi_csi_number(const std::string& csi);
    [[maybe_unused]] extern char get_ansi_csi_code(const std::string& csi);
    [[maybe_unused]] extern void handle_csi(const std::string& csi_str,
                                            std::string& dst_str,
                                            int32_t* dst_crsr_pos);

}  // namespace osm

#endif