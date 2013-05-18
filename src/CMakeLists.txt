
add_subdirectory(formats)

set(BinInfoSources
  main.cpp
)

add_executable(bininfo ${BinInfoSources})

target_link_libraries(bininfo
  ${CMAKE_THREAD_LIBS_INIT}
)
