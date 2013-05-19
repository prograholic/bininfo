#include <gtest/gtest.h>

#include <boost/static_assert.hpp>

#include <common/types.hpp>



template <typename IntT>
struct sized_int_holder
{
  union X
  {
    IntT int_val;
    common::uint8_t char_val[sizeof(IntT)];
  } x;
};



template <typename IntT>
class CheckEndianTest : public ::testing::Test
{

};

TYPED_TEST_CASE_P(CheckEndianTest);


TYPED_TEST_P(CheckEndianTest, CheckNativeMemToType)
{
  typedef TypeParam int_t;
  typedef sized_int_holder<int_t> int_holder_t;
  BOOST_STATIC_ASSERT(sizeof(int_holder_t) == sizeof(int_t));

  const common::uint8_t data [] =
  {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
  };

  BOOST_STATIC_ASSERT(sizeof(data) >= sizeof(int_t));


  int_holder_t h;
  h.x.int_val = common::endian::native_mem2type<int_t>(data);

  for (int i = 0; i != sizeof(int_t); ++i)
  {
    EXPECT_EQ(
          static_cast<common::uint16_t>(data[i]),
          static_cast<common::uint16_t>((h.x.char_val[i]))
          );
  }
}



TYPED_TEST_P(CheckEndianTest, CheckOppositeMemToType)
{
  typedef TypeParam int_t;
  typedef sized_int_holder<int_t> int_holder_t;
  BOOST_STATIC_ASSERT(sizeof(int_holder_t) == sizeof(int_t));

  const common::uint8_t data [] =
  {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
  };

  BOOST_STATIC_ASSERT(sizeof(data) >= sizeof(int_t));


  int_holder_t h;
  h.x.int_val = common::endian::opposite_mem2type<int_t>(data);

  for (int i = 0; i != sizeof(int_t); ++i)
  {
    ASSERT_LE(i, sizeof(data));

    EXPECT_EQ(
          static_cast<common::uint16_t>(data[sizeof(int_t) - (i + 1)]),
          static_cast<common::uint16_t>((h.x.char_val[i]))
          );
  }
}




REGISTER_TYPED_TEST_CASE_P(CheckEndianTest, CheckNativeMemToType, CheckOppositeMemToType);

typedef ::testing::Types
<
  common::uint8_t, common::int8_t,
  common::uint16_t, common::int16_t,
  common::uint32_t, common::int32_t,
  common::uint64_t, common::int64_t
>
KnownFixedSizeIntegerTypes;

INSTANTIATE_TYPED_TEST_CASE_P(CheckMemToTypeConversion, CheckEndianTest, KnownFixedSizeIntegerTypes);
