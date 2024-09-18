cmake_minimum_required(VERSION 3.28)
project(sudoku)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

add_executable(sudoku src/main.cpp
        src/board.cpp
        include/board.hpp
        src/game.cpp
        include/game.hpp
        src/file.cpp)
