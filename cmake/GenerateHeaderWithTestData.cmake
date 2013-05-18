

macro(CPPIFY_STRING INPUT OUTPUT)

  string(REGEX REPLACE
	"[\\*\\.\\[\\> \\:/-]"
	"_"
	TMP_OUT
	${${INPUT}}
  )

  # Weird CMake bug (cannot process closing ] inside [])
  string(REGEX REPLACE
	"\\]"
	"_"
	${OUTPUT}
	${TMP_OUT}
  )
endmacro()


function(GENERATE_HEADER_WITH_TEST_DATA dir)

  message(STATUS "generating header for directory [${dir}] ...")
  file(GLOB_RECURSE BIN_FILE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/${dir}" "*.bin")

  list(LENGTH BIN_FILE_LIST file_count)
  message(STATUS "  files count: ${file_count}")

  CPPIFY_STRING(dir local_filename)
  set(filename ${CMAKE_CURRENT_BINARY_DIR}/${local_filename}.hpp)

  file(WRITE ${filename}
	"// This file is automatically generated during configuring\n"
	"//All changes will be lost\n\n"
	"#ifndef BININFO_TESTS_GENERATED_${local_filename}_HEADER\n"
	"#define BININFO_TESTS_GENERATED_${local_filename}_HEADER\n\n"
	"namespace test_data\n"
	"{\n"
	"\n"
  )

  foreach(item ${BIN_FILE_LIST})
	file(RELATIVE_PATH local_item ${CMAKE_CURRENT_SOURCE_DIR} ${item})
	CPPIFY_STRING(local_item cpp_item)

	list(APPEND all_cpp_items ${cpp_item})
	file(APPEND ${filename}
	"  const char ${cpp_item} [] = \"${item}\";\n\n"
	)
  endforeach()

  if(all_cpp_items)
	list(GET all_cpp_items 0 first_item)
	list(REMOVE_AT all_cpp_items 0)

	file(APPEND ${filename}
	  "  /// All data in one variable (useful for iterating)\n"
	  "  const char * all_items [] =\n"
	  "  {\n"
	  "    ${first_item}"
	)
	foreach(cpp_item ${all_cpp_items})
	  file(APPEND ${filename}
		",\n    ${cpp_item}"
	  )
	endforeach()

	file(APPEND ${filename}
	  "    \n"
	  "  };\n"
	)
  endif()

  file(APPEND ${filename}
	"}\n"
	"#endif //BININFO_TESTS_GENERATED_${local_filename}_HEADER\n"
  )

endfunction()