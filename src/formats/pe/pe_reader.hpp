#ifndef BININFO_FORMATS_PE_PE_READER_HEADER
#define BININFO_FORMATS_PE_PE_READER_HEADER

#include <iosfwd>

#include <boost/noncopyable.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

#include "formats/pe/pe_description.hpp"

namespace fmt
{
  namespace pe
  {

    enum pe_reader_notification_result
    {
      pe_reader_stop,
      pe_reader_continue
    };

    class pe_reader_notifier_base : private boost::noncopyable
    {
    public:

      virtual ~pe_reader_notifier_base();

      virtual pe_reader_notification_result notify(const msdos::header & msdos_header) = 0;
    };
    typedef boost::shared_ptr<pe_reader_notifier_base> pe_reader_notifier_ptr;



    class pe_reader : private boost::noncopyable
    {
    public:
      pe_reader(std::istream & strm);

      void read(pe_reader_notifier_ptr notifier = pe_reader_notifier_ptr());

    private:
      std::istream & m_stream;


      pe_reader_notification_result read_msdos_header(pe_reader_notifier_ptr notifier);
    };
  }
}


#endif /* BININFO_FORMATS_PE_PE_READER_HEADER */
