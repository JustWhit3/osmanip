#ifndef ALIASES_HPP
#define ALIASES_HPP

#include <map>
#include <chrono>
#include <set>

namespace osm
 {
  //====================================================
  //     DATA CONTAINERS
  //====================================================
  using string_map = std::map <std::string, std::string>;
  using string_pair_map = std::map <std::string, std::pair<std::string, std::string>>;
  using string_set_map = std::map <std::string, std::set <std::string> >;

  //====================================================
  //     TIME TYPES
  //====================================================
  using steady_clock = std::chrono::steady_clock;
  using duration = std::chrono::duration <float, steady_clock::period>;
 }

#endif