cmake_minimum_required(VERSION 3.3)
project(Checkers CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused")


set(HEADER_FILES
        ../include/Board.h
        ../include/Color.h
        ../include/Game.h
        ../include/Piece.h
        ../include/Point.h
        ../include/Square.h
        ../include/TerminalSprite.h
        )

set(SOURCE_FILES
        Board.cpp
        Color.cpp
        Game.cpp
        Piece.cpp
        Square.cpp
        TerminalSprite.cpp
        )

# ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# boost
#find_package(Boost REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})

# TARGETS
# checkers library
add_library(checkers SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(checkers ${CURSES_LIBRARIES})

# the game
add_executable(runCheckers main.cpp)
target_link_libraries(runCheckers checkers)