#include <fstream>

#include <gtest/gtest.h>

#include <boost/scoped_ptr.hpp>

#include "formats/pe/pe_reader.hpp"

#include "data_fmt_pe.hpp"


class PeReaderTest : public ::testing::TestWithParam<const char * >
{
public:


  virtual void SetUp()
  {
    mInputStream.reset(new std::ifstream);
    mInputStream->exceptions(std::ifstream::failbit | std::ifstream::badbit);

    mInputStream->open(GetParam(), std::ios_base::binary);

    mReader.reset(new fmt::pe::pe_reader(*mInputStream));
  }



  virtual void TearDown()
  {

  }

  boost::scoped_ptr<std::ifstream> mInputStream;
  boost::scoped_ptr<fmt::pe::pe_reader> mReader;

};




TEST_P(PeReaderTest, ReadPeHeader)
{
  EXPECT_TRUE(1);
}


INSTANTIATE_TEST_CASE_P(PeReader, PeReaderTest, ::testing::ValuesIn(test_data::data_fmt_pe_all_items));
