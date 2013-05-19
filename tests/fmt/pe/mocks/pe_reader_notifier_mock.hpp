#ifndef BININFO_TESTS_FMT_PE_MOCKS_PE_READER_NOTIFIER_MOCK_HEADER
#define BININFO_TESTS_FMT_PE_MOCKS_PE_READER_NOTIFIER_MOCK_HEADER

#include <gmock/gmock.h>

#include "formats/pe/pe_reader.hpp"

namespace mocks
{
  class pe_reader_notifier_mock : public fmt::pe::pe_reader_notifier_base
  {
  public:

    MOCK_METHOD1(notify, fmt::pe::pe_reader_notification_result (const fmt::pe::msdos::header & msdos_header));
  };

  typedef boost::shared_ptr<pe_reader_notifier_mock> pe_reader_notifier_mock_ptr;
}


#endif /* BININFO_TESTS_FMT_PE_MOCKS_PE_READER_NOTIFIER_MOCK_HEADER */
