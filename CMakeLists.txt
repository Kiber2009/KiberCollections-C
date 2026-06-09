cmake_minimum_required(VERSION 4.2)
project(KiberCollections C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/sources/*.c")

add_library(KiberCollections STATIC ${SOURCES})

target_include_directories(KiberCollections PUBLIC "src/include")