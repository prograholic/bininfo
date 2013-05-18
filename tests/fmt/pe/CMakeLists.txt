
set(BinInfoTestsFmtPeSources
  main.cpp
  pe_reader_tests.cpp
)

add_executable(bininfo_tests_fmt_pe ${BinInfoTestsFmtPeSources})


target_link_libraries(bininfo_tests_fmt_pe
  ${CMAKE_THREAD_LIBS_INIT}
  gtest
)
