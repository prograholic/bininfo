
set(BinInfoFormatsPeSources
  pe_description.cpp
  pe_description.hpp
  pe_reader.cpp
  pe_reader.hpp
)

add_library(bininfo_formats_pe STATIC ${BinInfoFormatsPeSources})
