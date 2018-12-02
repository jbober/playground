#include <benchmark/benchmark.h>

#include <future>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

#include "fibonacci.h"
#include <string>

#include <stlab/concurrency/channel.hpp>
#include <stlab/concurrency/future.hpp>
#include <stlab/concurrency/default_executor.hpp>

using namespace boost::multiprecision;
using namespace std;

static void std_async(benchmark::State& state) {
  for (auto _ : state)
  {

  future<cpp_int> x = std::async([]{ return fibonacci<cpp_int>(1'000'000); });
  //future<cpp_int> y = std::async([]{ return fibonacci<cpp_int>(1'000'000); });
  }
}
BENCHMARK(std_async);

static void stlab_async(benchmark::State& state) {
  for (auto _ : state)
  {

  stlab::future<cpp_int> x = stlab::async(stlab::default_executor, []{ return fibonacci<cpp_int>(1'000'000); });
  //stlab::future<void> y = x.then([](stlab::future<cpp_int> x){ std::cout << x.get() << std::endl; });
  }
}
BENCHMARK(stlab_async);

BENCHMARK_MAIN();

