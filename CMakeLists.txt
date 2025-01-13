cmake_minimum_required(VERSION 3.5)
project(CList VERSION 1.0.0)

option(BUILD_SHARED_LIBS "Build the library as shared" ON)

file(GLOB_RECURSE SRC "./src/*.c")

add_library(clist ${SRC})
target_include_directories(clist PRIVATE "./include")

install(TARGETS clist
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set_target_properties(clist PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(clist PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(clist PROPERTIES PUBLIC_HEADER "include/clist.h")

configure_file(clist.pc.in clist.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/clist.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)