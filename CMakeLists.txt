cmake_minimum_required(VERSION 3.28)
project(sudoku)

set(CMAKE_CXX_STANDARD 26)

include_directories(include src)

add_executable(sudoku src/main.cpp
        src/board.cpp
        src/game.cpp
        src/file.cpp
        include/board.hpp
        include/file.hpp
        include/game.hpp)
