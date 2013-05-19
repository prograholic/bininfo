#ifndef BININFO_COMMON_TYPES_HEADER
#define BININFO_COMMON_TYPES_HEADER

#include <algorithm>

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


  namespace detail
  {
    template <typename InputPointerT>
    struct resolve_intermediate_void_ptr_type
    {
      typedef void * ptr_t;
    };


    template <typename InputT>
    struct resolve_intermediate_void_ptr_type<const InputT *>
    {
      typedef const void * ptr_t;
    };
  }

  template <typename OutputPointerT, typename InputPointerT>
  OutputPointerT ptr_cast(InputPointerT * input)
  {
    typedef typename detail::resolve_intermediate_void_ptr_type<InputPointerT>::ptr_t intermediate_t;
    return static_cast<OutputPointerT>(static_cast<intermediate_t>(input));
  }





  namespace endian
  {
    template <typename ValueT, typename InputIteratorT>
    ValueT native_mem2type(InputIteratorT input)
    {
      size_t len = sizeof(ValueT);
      ValueT result;
      uint8_t * ptr = ptr_cast<uint8_t *>(&result);

      while (len > 0)
      {
        *ptr = *input;
        ++ptr;
        ++input;

        --len;
      }

      return result;
    }


    template <typename ValueT, typename InputIteratorT>
    ValueT opposite_mem2type(InputIteratorT input)
    {
      size_t len = sizeof(ValueT);
      ValueT result;
      uint8_t * ptr = ptr_cast<uint8_t *>(&result) + len;

      while (len > 0)
      {
        --ptr;
        *ptr = *input;
        ++input;

        --len;
      }

      return result;
    }


    #ifndef BININFO_BIG_ENDIAN
      #error "BININFO_BIG_ENDIAN must be defined"
    #endif

    template <typename ValueT, typename InputIteratorT>
    ValueT be_mem_to_type(InputIteratorT input)
    {
#if (BININFO_BIG_ENDIAN == 1)
      return native_mem2type<ValueT>(input);
#else /* BININFO_BIG_ENDIAN */
      return opposite_mem2type<ValueT>(input);
#endif /* BININFO_BIG_ENDIAN */
    }


    template <typename ValueT, typename InputIteratorT>
    ValueT le_mem_to_type(InputIteratorT input)
    {
#if (BININFO_BIG_ENDIAN == 1)
      return opposite_mem2type<ValueT>(input);
#else /* BININFO_BIG_ENDIAN */
      return native_mem2type<ValueT>(input);
#endif /* BININFO_BIG_ENDIAN */
    }

  }

}

#endif /* BININFO_COMMON_TYPES_HEADER */
