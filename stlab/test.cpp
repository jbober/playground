#include <gtest/gtest.h>
#include <atomic>
#include <iostream>
#include <thread>

#include <stlab/concurrency/channel.hpp>
#include <stlab/concurrency/default_executor.hpp>

using namespace std;
using namespace stlab;

TEST(stlab_tests, sanity_check2)
{
	EXPECT_EQ(2+2, 4);
}

TEST(stlab_tests, join_test)
{
sender<int> send1, send2;
    receiver<int> receive1, receive2;

    tie(send1, receive1) = channel<int>(default_executor);
    tie(send2, receive2) = channel<int>(default_executor);

    std::atomic_bool done{ false };

    auto joined = stlab::zip_with(default_executor, 
                      [](int x, int y) { return x + y; }, // x will get 1, y will get 2
                      receive1, 
                      receive2)
        | [&_done = done](int x) { 
              cout << x << '\n'; 
              _done = true; 
          };

    receive1.set_ready();
    receive2.set_ready();

    send1(1);
    send2(2);
}
