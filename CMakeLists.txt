cmake_minimum_required(VERSION 2.8)

project(bininfo)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(FeatureSummary)
include(GenerateHeaderWithTestData)

find_package(Threads REQUIRED)
#find_package(Boost REQUIRED)


add_subdirectory(src)

if (BININFO_DISABLE_TESTING)
  message(WARNING "Testing disabled")
else()
  add_subdirectory(tests)
endif()


FEATURE_SUMMARY(WHAT ALL)
