#ifndef BININFO_FORMATS_PE_PE_READER_HEADER
#define BININFO_FORMATS_PE_PE_READER_HEADER

#include <iosfwd>

#include <boost/noncopyable.hpp>

#include "formats/pe/pe_description.hpp"

namespace fmt
{
  namespace pe
  {
    class pe_reader : private boost::noncopyable
    {
    public:
      pe_reader(std::istream & strm);


    private:
      std::istream & mStream;

    };
  }
}


#endif /* BININFO_FORMATS_PE_PE_READER_HEADER */
