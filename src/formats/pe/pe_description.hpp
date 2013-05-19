#ifndef BININFO_FORMATS_PE_PE_DESCRIPTION_H
#define BININFO_FORMATS_PE_PE_DESCRIPTION_H

#include "common/types.hpp"

namespace fmt
{
  namespace pe
  {
    namespace msdos
    {
      struct header
      {
        common::uint16_t e_cblp;          // Bytes on last page of file
        common::uint16_t e_cp;            // Pages in file
        common::uint16_t e_crlc;          // Relocations
        common::uint16_t e_cparhdr;       // Size of header in paragraphs
        common::uint16_t e_minalloc;      // Minimum extra paragraphs needed
        common::uint16_t e_maxalloc;      // Maximum extra paragraphs needed
        common::uint16_t e_ss;            // Initial (relative) SS value
        common::uint16_t e_sp;            // Initial SP value
        common::uint16_t e_csum;          // Checksum
        common::uint16_t e_ip;            // Initial IP value
        common::uint16_t e_cs;            // Initial (relative) CS value
        common::uint16_t e_lfarlc;        // File address of relocation table
        common::uint16_t e_ovno;          // Overlay number
        common::uint16_t e_res[4];        // Reserved words
        common::uint16_t e_oemid;         // OEM identifier (for e_oeminfo)
        common::uint16_t e_oeminfo;       // OEM information; e_oemid specific
        common::uint16_t e_res2[10];      // Reserved words
        common::int32_t  e_lfanew;        // File address of new exe header
      };

      struct stub_program
      {
      };
    }

    struct header
    {

    };

    struct optional_header
    {

    };

    struct text_header
    {

    };

    struct bss_header
    {

    };

    struct rdata_header
    {

    };

    struct debug_header
    {

    };


  }
}


#endif // BININFO_FORMATS_PE_PE_DESCRIPTION_H
