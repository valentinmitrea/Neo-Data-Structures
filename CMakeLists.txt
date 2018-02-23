cmake_minimum_required(VERSION 2.8)
project(Neo-Data-Structures C)

# set the version of the project
set(Neo-Data-Structures_VERSION_MAJOR 1)
set(Neo-Data-Structures_VERSION_MINOR 0)
set(Neo-Data-Structures_VERSION_PATCH 1)

# configure options and build mode for the project
option(BUILD_TESTS "Build tests for the library" OFF)
set(CMAKE_BUILD_TYPE Release)

# verify the version of the available C compiler
if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
	if(CMAKE_C_COMPILER_VERSION VERSION_LESS "4.4.0")
		message(FATAL_ERROR "Minimum supported version of GCC is 4.4.0!")
	endif()
endif()

# declare the header files directory
include_directories(include)

# add the source files directory
add_subdirectory(src)

# generate tests for the library (only if testing is enabled in the build process)
if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif(BUILD_TESTS)
