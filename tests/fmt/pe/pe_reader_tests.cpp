#include <fstream>
#include <stdexcept>

#include <gtest/gtest.h>

#include <boost/scoped_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>

#include "formats/pe/pe_reader.hpp"

#include "mocks/pe_reader_notifier_mock.hpp"

#include "data_fmt_pe.hpp"



using ::testing::_;
using ::testing::AnyNumber;
using ::testing::Return;
using ::testing::Field;
using ::testing::Eq;
using ::testing::Throw;


class PeReaderTest : public ::testing::TestWithParam<const char * >
{
public:


  virtual void SetUp()
  {
    setupVariables();
    setupMockBehaviour();
  }



  virtual void TearDown()
  {
    tearDownVariables();
  }

  fmt::pe::pe_reader_notifier_ptr mReaderNotifier;
  boost::scoped_ptr<std::ifstream> mInputStream;
  boost::scoped_ptr<fmt::pe::pe_reader> mReader;
  mocks::pe_reader_notifier_mock_ptr mNotifierMock;


private:

  void setupVariables()
  {
    mInputStream.reset(new std::ifstream);
    mInputStream->exceptions(std::ifstream::failbit | std::ifstream::badbit);

    mInputStream->open(GetParam(), std::ios_base::binary);

    mReader.reset(new fmt::pe::pe_reader(*mInputStream));

    mNotifierMock = boost::make_shared<mocks::pe_reader_notifier_mock>();
  }

  void tearDownVariables()
  {
    mNotifierMock.reset();
    mReader.reset();
    mInputStream.reset();
  }

  void setupMockBehaviour()
  {
    ON_CALL(*mNotifierMock, notify(_)).WillByDefault(Throw(std::runtime_error("Unexpected mock call")));
  }

};




TEST_P(PeReaderTest, ReadPeHeader)
{
  EXPECT_CALL(*mNotifierMock, notify(Field(&fmt::pe::msdos::header::e_magic, Eq(fmt::pe::msdos::msdos_magic)))).
      WillOnce(Return(fmt::pe::pe_reader_stop));

  ASSERT_NO_THROW(mReader->read(mNotifierMock));
}


INSTANTIATE_TEST_CASE_P(PeReader, PeReaderTest, ::testing::ValuesIn(test_data::data_fmt_pe_all_items));
