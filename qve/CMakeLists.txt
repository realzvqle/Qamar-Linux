cmake_minimum_required(VERSION 3.10)
project(qve)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(qve ${SOURCES})

target_link_libraries(qve --static)

set_target_properties(qve PROPERTIES LINK_SEARCH_START_STATIC TRUE)
