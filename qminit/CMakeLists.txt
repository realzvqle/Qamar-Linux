cmake_minimum_required(VERSION 3.10)
project(init)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(init ${SOURCES})

target_link_libraries(init --static)

set_target_properties(init PROPERTIES LINK_SEARCH_START_STATIC TRUE)
