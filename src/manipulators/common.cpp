//====================================================
//     Headers
//====================================================

//My headers
#include "../include/manipulators/common.hpp"

//Extra headers
#include <arsenalgear/utils.hpp>

//STD headers
#include <iostream>
#include <string>
#include <unordered_map>

namespace osm
 {
  //====================================================
  //     feat (first overload)
  //====================================================
  /**
   * @brief It takes an std::map object as the first argument and an std::string object (map key) as the second argument and returns the interested color / style feature by returning the map value from the corresponding key.
   * 
   * @param generic_map The feature map.
   * @param feat_string The feature name.
   * @return const std::string& The output feature.
   */
  const std::string& feat( const std::unordered_map <std::string, std::string>& generic_map, const std::string& feat_string )
   {
    try
     {
      return generic_map.at( feat_string );
     }
    catch( const std::exception& except )
     {
      throw agr::except_error_func( generic_map.at( "error" ), feat_string, "is not supported!" );
     }
   }
 }