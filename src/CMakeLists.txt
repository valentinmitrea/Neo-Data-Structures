# source files and compilation flags
set(SOURCES ndsvector.c)
set(CMAKE_C_FLAGS "-std=c99 -O3 -Werror -pedantic -Wall -Wextra -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wcast-qual")

# generate a shared library from the sources
add_library(nds SHARED ${SOURCES})
set_target_properties(nds PROPERTIES VERSION ${Neo-Data-Structures_VERSION_MAJOR}.${Neo-Data-Structures_VERSION_MINOR}.${Neo-Data-Structures_VERSION_PATCH} SOVERSION ${Neo-Data-Structures_VERSION_MAJOR})

# configure where to install the shared library
if(UNIX)
	set(INCLUDE_DIRECTORY "/usr/include/nds/")
	set(LIB_DIRECTORY "/usr/lib/")
endif(UNIX)

install(FILES ${CMAKE_SOURCE_DIR}/include/nds/nds.h ${CMAKE_SOURCE_DIR}/include/nds/ndsvector.h DESTINATION ${INCLUDE_DIRECTORY})
install(TARGETS nds DESTINATION ${LIB_DIRECTORY})
