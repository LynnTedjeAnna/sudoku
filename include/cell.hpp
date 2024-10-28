//
// Created by Lynn Meindertsma on 10/10/2024.
//

#ifndef SUDOKU_CELL_HPP
#define SUDOKU_CELL_HPP
#include <iostream>

class Cell {
public:
    // constructor
    Cell() = default;

    //getter and setter
    uint8_t get();
    void set(uint8_t val);
private:
    uint8_t value;
    // todo: differentiate between visible and invisible values!!!
    // todo: notations (possibilities)
};

#endif //SUDOKU_CELL_HPP
