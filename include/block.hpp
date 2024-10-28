//
// Created by Lynn Meindertsma on 10/10/2024.
//

#ifndef SUDOKU_BLOCK_HPP
#define SUDOKU_BLOCK_HPP
#include "grid.hpp"
#include "cell.hpp"
#include "allowed.hpp"

class Block : public Grid{
public:
    //constructor
    Block() = default;

    //todo: finish functions reset
    void reset() override;
    void print() override;

    //getter and setter
    uint8_t get(uint8_t x, uint8_t y);              // todo x, y: min 0, max 2
    void set(uint8_t x, uint8_t y, uint8_t val);    // todo x, y: min 0, max 2

private:
    Allowed allowed;        // Composition: uses an Allowed object to keep track of allowed values
    Cell cells[3][3];       // Composition: A Block is made of Cells
    friend class Board;
};


#endif //SUDOKU_BLOCK_HPP
