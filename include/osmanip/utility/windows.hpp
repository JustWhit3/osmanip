//====================================================
//     File data
//====================================================
/**
 * @file windows.hpp
 * @author Gianluca Bianco
 * (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef OSMANIP_UTILITY_WINDOWS_HPP
#define OSMANIP_UTILITY_WINDOWS_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <string>

namespace osm {

    //====================================================
    //     Variables
    //====================================================
    extern std::string old_chcp;

    //====================================================
    //     Functions
    //====================================================
    extern void enableANSI();
    extern void disableANSI();
    extern void enableUNICODE();
    extern void disableUNICODE();
}  // namespace osm

#endif