

set(BinInfoTestsCommonSources
  test_endian.cpp
)



add_executable(bininfo_tests_common ${BinInfoTestsCommonSources})


target_link_libraries(bininfo_tests_common
  gtest
  gmock_main
)

add_test(bininfo_tests_common bininfo_tests_common)
