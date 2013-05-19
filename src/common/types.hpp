#ifndef BININFO_COMMON_TYPES_HEADER
#define BININFO_COMMON_TYPES_HEADER

#include <boost/cstdint.hpp>

namespace common
{
  typedef boost::uint8_t uint8_t;
  typedef boost::int8_t int8_t;

  typedef boost::uint16_t uint16_t;
  typedef boost::int16_t int16_t;

  typedef boost::uint32_t uint32_t;
  typedef boost::int32_t int32_t;

  typedef boost::uint64_t uint64_t;
  typedef boost::int64_t int64_t;

  namespace mem
  {
    typedef uint8_t word16_t [2];
    typedef uint8_t word32_t [4];
    typedef uint8_t word64_t [8];
  }


}

#endif /* BININFO_COMMON_TYPES_HEADER */
