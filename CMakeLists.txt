cmake_minimum_required(VERSION 2.8)

project(bininfo)


include(FeatureSummary)


find_package(Boost REQUIRED)
find_package(GTest)
#find_package(GMock)

add_subdirectory(src)








if (GTEST_FOUND)
  add_subdirectory(tests)
else()
  message(WARNING "Google Test cannot be found, testing disabled")
endif()






FEATURE_SUMMARY(WHAT ALL)
