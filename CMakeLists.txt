cmake_minimum_required(VERSION 2.8)

project(bininfo)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(FeatureSummary)
include(GenerateHeaderWithTestData)
include(TestBigEndian)



TEST_BIG_ENDIAN(ENDIANNESS)
add_definitions(-DBININFO_BIG_ENDIAN=${ENDIANNESS})

find_package(Threads REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(src)

add_subdirectory(src)

if (BININFO_DISABLE_TESTING)
  message(WARNING "Testing disabled")
else()
  enable_testing()
  add_subdirectory(tests)
endif()


FEATURE_SUMMARY(WHAT ALL)
