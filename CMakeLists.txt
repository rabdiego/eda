cmake_minimum_required(VERSION 3.7)
project(EDA)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "libs/*.hpp" "libs/*.cpp" )
include_directories(${CMAKE_SOURCE_DIR})
include_directories (/usr/include/freetype2)

add_library(eva
    ${LIB_SOURCES}/eva/
)

add_executable(test src/test.cpp)

target_link_libraries(test eva)

install(TARGETS test)
