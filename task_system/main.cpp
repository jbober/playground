#include <iostream>
#include <future>
#include <boost/multiprecision/cpp_int.hpp>
#include "fibonacci.h"

using namespace boost::multiprecision;
using namespace std;

int main()
{
  future<cpp_int> x = std::async([]{ return fibonacci<cpp_int>(1'000'000); });
  std::cout << x.get();
}
