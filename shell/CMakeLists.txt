cmake_minimum_required(VERSION 3.10)
project(shell)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(shell ${SOURCES})

target_link_libraries(shell --static)

set_target_properties(shell PROPERTIES LINK_SEARCH_START_STATIC TRUE)
