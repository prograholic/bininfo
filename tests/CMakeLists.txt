add_subdirectory(3rdparty)

include_directories(3rdparty/gtest/include)
include_directories(3rdparty/gmock/include)

GENERATE_HEADER_WITH_TEST_DATA("data/fmt/pe")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(fmt)
