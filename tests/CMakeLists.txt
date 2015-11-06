cmake_minimum_required(VERSION 3.3)
project(CheckersTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# google test stuff
set(GTEST_ROOT ~/repos/googletest/googletest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(TEST_FILES
    BoardTest.h
    ColorTest.h
    GameTest.h
    PieceTest.h
    PointTest.h
    SquareTest.h
    TerminalSpriteTest.h
)

add_executable(runTests tests.cpp ${TEST_FILES})
target_link_libraries(runTests checkers ${GTEST_BOTH_LIBRARIES})