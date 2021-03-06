#!/usr/bin/env bash

# Configure, build and run performance benchmarks

set -euo pipefail

PROJECT_DIR=$(
  cd "$(dirname "$0")"/../..
  pwd
)

conan install \
  --build missing \
  --options target=test-benchmark \
  "${PROJECT_DIR}" \
  "$@"

conan build \
  --build \
  --configure \
  "${PROJECT_DIR}"

test/benchmark/test-benchmark --benchmark_format=csv | tee result.csv
"${PROJECT_DIR}"/test/benchmark/report.py result.csv
