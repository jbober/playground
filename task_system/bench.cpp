#include <benchmark/benchmark.h>

#include <future>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

#include "fibonacci.h"
#include <string>

using namespace boost::multiprecision;

static void std_async(benchmark::State& state) {
  for (auto _ : state)
  {

  std::future<cpp_int> x = std::async([]{ return fibonacci<cpp_int>(1'000'000); });
  }
}
BENCHMARK(std_async);

BENCHMARK_MAIN();

