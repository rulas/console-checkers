cmake_minimum_required(VERSION 3.3)
project(Checkers CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Board.cpp
    Color.cpp
    Game.cpp
    Piece.cpp
    Point.cpp
    Square.cpp
    TerminalSprite.cpp
)

add_library(checkers SHARED ${SOURCE_FILES})
add_executable(runCheckers main.cpp)
target_link_libraries(runCheckers checkers)