//====================================================
//     Headers
//====================================================

// My headers
#include "../../../include/manipulators/colsty.hpp"
#include "../../../include/manipulators/cursor.hpp"

// Headers for comparison
#include "../deps/termcolor.hpp"

// Extra headers
#include <benchmark/benchmark.h>

// STD headers
#include <iostream>
#include <string>

//====================================================
//     Namespace directives
//====================================================
namespace bm = benchmark;

//====================================================
//     osmanip
//====================================================

// osmanip_common_feat
static void osmanip_common_feat( bm::State& state ) 
 {
  for ( auto _ : state ) bm::DoNotOptimize( std::cout << osm::feat( osm::col, "red" ) );
  std::cout << osm::reset( "color" );
 }

// osmanip_colsty_reset
static void osmanip_colsty_reset( bm::State& state ) 
 {
  for ( auto _ : state ) bm::DoNotOptimize( std::cout << osm::reset( "color" ) );
 }

// osmanip_colsty_RGB
static void osmanip_colsty_RGB( bm::State& state ) 
 {
  for ( auto _ : state ) bm::DoNotOptimize( std::cout << osm::RGB( 2, 4, 6 ) );
 }

// osmanip_cursor_feat
static void osmanip_cursor_feat( bm::State& state ) 
 {
  for ( auto _ : state ) bm::DoNotOptimize( std::cout << osm::feat( osm::crs, "left", 0 ) );
 }

// osmanip_cursor_go_to
static void osmanip_cursor_go_to( bm::State& state ) 
 {
  for ( auto _ : state ) bm::DoNotOptimize( osm::go_to( 0, 0 ) );
 }

//====================================================
//     termcolor
//====================================================

// termcolor_feat
static void termcolor_feat( bm::State& state ) 
 {
  for ( auto _ : state )bm::DoNotOptimize( std::cout << termcolor::red );
 }

// termcolor_reset
static void termcolor_reset( bm::State& state ) 
 {
  for ( auto _ : state )bm::DoNotOptimize( std::cout << termcolor::reset );
 }

//====================================================
//     Benchmarking settings
//====================================================

// osmanip
BENCHMARK( osmanip_common_feat );
BENCHMARK( osmanip_colsty_reset );
BENCHMARK( osmanip_colsty_RGB );
BENCHMARK( osmanip_cursor_feat );
BENCHMARK( osmanip_cursor_go_to );

// termcolor
BENCHMARK( termcolor_feat );
BENCHMARK( termcolor_reset );

BENCHMARK_MAIN();