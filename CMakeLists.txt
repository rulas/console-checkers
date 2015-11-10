cmake_minimum_required(VERSION 3.3)
project(Checkers)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(./include)

add_subdirectory(source)
add_subdirectory(tests)