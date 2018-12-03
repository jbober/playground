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
using namespace stlab;
using std::cout;
using std::endl;

static void std_async(benchmark::State& state) {
  for (auto _ : state)
  {

  auto x = std::async([]{ return fibonacci<cpp_int>(1'000'000); });
  }
}
BENCHMARK(std_async);

static void stlab_async(benchmark::State& state) {
  for (auto _ : state)
  {

  auto x = stlab::async(default_executor, []{ return fibonacci<cpp_int>(1'000'000); });
  future<void> y = x.then([](cpp_int x){ cout << x << endl; });
  y.get_try();
  }
}
BENCHMARK(stlab_async);

BENCHMARK_MAIN();

