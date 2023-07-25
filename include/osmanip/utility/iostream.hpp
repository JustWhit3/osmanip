//====================================================
//     File data
//====================================================
/**
 * @file iostream.hpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-11-2
 * @copyright Copyright (c) 2022 Gianluca Bianco
 * under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================

#pragma once
#ifndef OSMANIP_UTILITY_IOSTREAM_HPP
#define OSMANIP_UTILITY_IOSTREAM_HPP

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/utility/output_redirector.hpp>

// STD headers
#include <ostream>

namespace osm {

    //====================================================
    //     Global variables
    //====================================================

    extern std::ostream cout;          /// Linked to standard output
    extern OutputRedirector redirout;  /// Linked to output
                                       /// redirection

}  // namespace osm

#endif  // OSMANIP_COUT_INCLUDE_UTILITY_IOSTREAM_HPP
