#include "pe_reader.hpp"

#include <boost/smart_ptr/make_shared.hpp>
#include <boost/assert.hpp>

#include "pe_description_internal.hpp"


namespace fmt
{
  namespace pe
  {

    namespace
    {
      class empty_pe_reader_notifier : public pe_reader_notifier_base
      {
      public:

        virtual pe_reader_notification_result notify(const msdos::header & /* msdos_header */)
        {
          return pe_reader_continue;
        }
      };
    }

    pe_reader_notifier_base::~pe_reader_notifier_base()
    {

    }

    pe_reader::pe_reader(std::istream & strm)
      : m_stream(strm)
    {

    }


    void pe_reader::read(pe_reader_notifier_ptr notifier)
    {
      if (!notifier)
      {
        notifier = boost::make_shared<empty_pe_reader_notifier>();
      }
      BOOST_ASSERT(!!notifier && "notifier is not set, program error");

      if (read_msdos_header(notifier) == pe_reader_stop)
      {
        return;
      }
    }



    pe_reader_notification_result pe_reader::read_msdos_header(pe_reader_notifier_ptr notifier)
    {
      msdos::header msdos_header;

      internal::IMAGE_DOS_HEADER internalDosHeader;

      m_stream.read(common::ptr_cast<char *>(&internalDosHeader), sizeof(internalDosHeader));

      msdos_header.e_magic = common::endian::le_mem_to_type<common::uint16_t>(internalDosHeader.e_magic);

      return notifier->notify(msdos_header);
    }
  }
}
