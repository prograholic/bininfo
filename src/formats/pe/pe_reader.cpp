#include "pe_reader.hpp"

#include "pe_description_internal.hpp"


namespace fmt
{
  namespace pe
  {
    pe_reader::pe_reader(std::istream & strm)
      : mStream(strm)
    {

    }
  }
}
