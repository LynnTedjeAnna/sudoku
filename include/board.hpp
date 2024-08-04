//
// Created by Lynn Meindertsma on 02/08/2024.
//

#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <cstdint>


class Block {
public:
    //constructor
    Block() = default;

    //getter and setter
    uint8_t get(uint8_t x, uint8_t y);
    void set(uint8_t x, uint8_t y, uint8_t val);
private:
    uint8_t cells[3][3];
};


class Board {
public:
    //constructor
    Board() = default;

    //Methode to print board
    void print_board();

    //Methode to generate board
    void gen_board();



private:
    Block blocks[3][3];
};

#endif //SUDOKU_BOARD_HPP
