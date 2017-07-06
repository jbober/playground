#include <cstddef>
#include <boost/fusion/include/define_struct.hpp>

BOOST_FUSION_DEFINE_STRUCT(
    (example), header,
    (uint8_t, magic)
    (uint8_t, version)
    (uint32_t, length)
    (uint32_t, msg_type)
)
