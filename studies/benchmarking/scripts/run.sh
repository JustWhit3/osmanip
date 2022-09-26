#!/bin/bash

./bin/"$1" \
--benchmark_out=data/manipulators.json \
--benchmark_repetitions=1 \
--benchmark_display_aggregates_only=false \
--benchmark_report_aggregates_only=false