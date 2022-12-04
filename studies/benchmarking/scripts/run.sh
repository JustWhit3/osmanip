#!/bin/bash

# Compile the code
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Run the script
./build/"$1" \
--benchmark_out=data/manipulators.json \
--benchmark_repetitions=1 \
--benchmark_display_aggregates_only=false \
--benchmark_report_aggregates_only=false