//====================================================
//     File data
//====================================================
/**
 * @file iostream.cpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-11-2
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include <include/utility/iostream.hpp>
#include <include/utility/sstream.hpp>
#include <include/utility/output_redirector.hpp>

#include <iostream>

namespace osm
{

  //====================================================
  //     Global variables
  //====================================================

  Ostreambuf cout_buf{ &std::cout };      // NOLINT(cppcoreguidelines-interfaces-global-init)
  std::ostream cout( &cout_buf );               /// Link to osm::cout

  OutputRedirector redirout{};

}      // namespace osm