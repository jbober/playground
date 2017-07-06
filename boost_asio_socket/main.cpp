#include <iostream>
#include <array>

#include <boost/asio/ip/tcp.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/asio/buffer.hpp>

#include "struct.h"
#include <arpa/inet.h>

namespace net {

template<class T> T ntoh(T) = delete;
uint32_t ntoh(uint32_t v) { return ntohl(v); }
uint16_t ntoh(uint16_t v) { return ntohs(v); }
uint8_t ntoh(uint8_t v) { return v; }
int8_t ntoh(int8_t v) { return v; }
char ntoh(char v) { return v; }

template<class T> T hton(T) = delete;
uint32_t hton(uint32_t v) { return htonl(v); }
uint16_t hton(uint16_t v) { return htons(v); }
uint8_t hton(uint8_t v) { return v; }
int8_t hton(int8_t v) { return v; }
char hton(char v) { return v; }

} // namespace net

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace net;

struct reader {
    mutable asio::const_buffer buf_;

    explicit reader(asio::const_buffer buf)
        : buf_(std::move(buf))
    { }

    template<class T>
    auto operator()(T & val) const ->
        typename std::enable_if<std::is_integral<T>::value>::type {
        val = ntoh(*asio::buffer_cast<T const*>(buf_));
        buf_ = buf_ + sizeof(T);
    }
};

template<typename T>
std::pair<T, asio::const_buffer> read(asio::const_buffer b) {
    reader r(std::move(b));
    T res;
    fusion::for_each(res, r);
    return std::make_pair(res, r.buf_);
}

int main(int argc, char *argv[])
{
    std::array<char, 12> a1 {static_cast<char>('0x01'), static_cast<char>('0x02'),  static_cast<char>('0x03'), static_cast<char>('0x04'), static_cast<char>('0x05'), static_cast<char>('0x06'), static_cast<char>('0x07'), static_cast<char>('0x08'), static_cast<char>('0x09'), static_cast<char>('0x0A'), static_cast<char>('0x0B'), static_cast<char>('0x0C')};
    auto t = read<example::header>(buffer (a1));
    cout << "Hello World!" << endl;

    cout << "uint16 :" << sizeof(uint16_t) << "\n";
    cout << "uint32 :" << sizeof(uint32_t) << "\n";
    return 0;
}

ip::tcp::socket sock(io_service);
