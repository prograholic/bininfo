#ifndef BININFO_FORMATS_PE_PE_DESCRIPTION_INTERNAL_HEADER
#define BININFO_FORMATS_PE_PE_DESCRIPTION_INTERNAL_HEADER

#include <boost/static_assert.hpp>

#include "common/types.hpp"

namespace fmt
{
  namespace pe
  {
    namespace internal
    {

      typedef struct _IMAGE_DOS_HEADER // DOS .EXE header (declared like in WINNT.H)
      {
        common::mem::word16_t e_magic;         // Magic number
        common::mem::word16_t e_cblp;          // Bytes on last page of file
        common::mem::word16_t e_cp;            // Pages in file
        common::mem::word16_t e_crlc;          // Relocations
        common::mem::word16_t e_cparhdr;       // Size of header in paragraphs
        common::mem::word16_t e_minalloc;      // Minimum extra paragraphs needed
        common::mem::word16_t e_maxalloc;      // Maximum extra paragraphs needed
        common::mem::word16_t e_ss;            // Initial (relative) SS value
        common::mem::word16_t e_sp;            // Initial SP value
        common::mem::word16_t e_csum;          // Checksum
        common::mem::word16_t e_ip;            // Initial IP value
        common::mem::word16_t e_cs;            // Initial (relative) CS value
        common::mem::word16_t e_lfarlc;        // File address of relocation table
        common::mem::word16_t e_ovno;          // Overlay number
        common::mem::word16_t e_res[4];        // Reserved words
        common::mem::word16_t e_oemid;         // OEM identifier (for e_oeminfo)
        common::mem::word16_t e_oeminfo;       // OEM information; e_oemid specific
        common::mem::word16_t e_res2[10];      // Reserved words
        common::mem::word32_t e_lfanew;        // File address of new exe header
      } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;


      /// Wrong structure sizeof, configure compiler data alignment
      BOOST_STATIC_ASSERT(64 == sizeof(IMAGE_DOS_HEADER));

    }
  }
}

#endif // BININFO_FORMATS_PE_PE_DESCRIPTION_INTERNAL_HEADER
