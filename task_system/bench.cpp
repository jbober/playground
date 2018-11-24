#include <benchmark/benchmark.h>

#include <future>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

#include "fibonacci.h"
#include <string>

using namespace boost::multiprecision;

//static void std_async(benchmark::State& state) {
//  for (auto _ : state)
//  {
//  std::string empty_string;
//
//  //std::future<cpp_int> x = std::async([]{ return fibonacci<cpp_int>(1'000'000); });
//  //auto x = fibonacci<cpp_int>(1'000'000);
//  //std::cout << x.get();
//  }
//}
//BENCHMARK(std_async);
//
static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

BENCHMARK_MAIN();

