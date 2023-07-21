//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/manipulators/colsty.hpp>
#include <osmanip/manipulators/cursor.hpp>
#include <osmanip/manipulators/decorator.hpp>

// Headers for comparison
#include <termcolor/termcolor.hpp>

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
static void osmanip_common_feat(bm::State& state) {
    for (auto _ : state)
        bm::DoNotOptimize(std::cout << osm::feat(osm::col, "red"));
    std::cout << osm::feat(osm::rst, "color");
}

// osmanip_colsty_RGB
static void osmanip_colsty_RGB(bm::State& state) {
    for (auto _ : state) bm::DoNotOptimize(std::cout << osm::RGB(2, 4, 6));
}

// osmanip_cursor_feat
static void osmanip_cursor_feat(bm::State& state) {
    for (auto _ : state)
        bm::DoNotOptimize(std::cout << osm::feat(osm::crs, "left", 0));
}

// osmanip_cursor_go_to
static void osmanip_cursor_go_to(bm::State& state) {
    for (auto _ : state) bm::DoNotOptimize(osm::go_to(0, 0));
}

// osmanip_printer_print
/*static void osmanip_printer_print( bm::State& state )
 {
  for ( auto _ : state ) bm::DoNotOptimize( osm::print( std::cout, "" ) );
 }

// osmanip_printer_print_default
static void osmanip_printer_print_default( bm::State& state )
 {
  for ( auto _ : state ) bm::DoNotOptimize( osm::print( "" ) );
 }*/

//====================================================
//     termcolor
//====================================================

// termcolor_feat
static void termcolor_feat(bm::State& state) {
    for (auto _ : state) bm::DoNotOptimize(std::cout << termcolor::red);
}

//====================================================
//     Benchmarking settings
//====================================================

// osmanip
BENCHMARK(osmanip_common_feat);
BENCHMARK(osmanip_colsty_RGB);
BENCHMARK(osmanip_cursor_feat);
BENCHMARK(osmanip_cursor_go_to);
/*BENCHMARK( osmanip_printer_print );
BENCHMARK( osmanip_printer_print_default );*/

// termcolor
BENCHMARK(termcolor_feat);

BENCHMARK_MAIN();