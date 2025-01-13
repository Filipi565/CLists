cmake_minimum_required(VERSION 3.12)
project(CList VERSION 1.0.1)

option(BUILD_SHARED_LIBS "Build the library as shared" ON)

file(GLOB_RECURSE SRC "./src/*.c")

add_library(clist ${SRC})
target_include_directories(clist PRIVATE "./include")

add_compile_definitions(CLIST_BUILD_LIB=)

if (${BUILD_SHARED_LIBS})
    add_compile_definitions(BUILD_LIBTYPE_SHARED=)
    set(CLIST_DLL_MACRO "#define CLIST_DLL")
else()
    set(CLIST_DLL_MACRO "")
endif(${BUILD_SHARED_LIBS})

configure_file(./include/clist.h clist.h @ONLY)

set_target_properties(clist PROPERTIES VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${CMAKE_BINARY_DIR}/clist.h")

configure_file(./cmake/clist.pc.in clist.pc @ONLY)

install(TARGETS clist
    LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/include")

install(FILES ${CMAKE_BINARY_DIR}/clist.pc
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)