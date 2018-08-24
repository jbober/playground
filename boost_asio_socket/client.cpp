#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

int main()
{
boost::asio::io_service io_service; // 1
boost::asio::ip::tcp::resolver resolver(io_service); // 2
boost::asio::ip::tcp::resolver::query query("localhost", "1234"); // 3
boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
boost::asio::ip::tcp::resolver::iterator end; // 4
	return 0;
}
