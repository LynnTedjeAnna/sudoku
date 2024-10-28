//
// Created by Lynn Meindertsma on 02/08/2024.
//

#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <cstdint>
#include "file.hpp"
#include "block.hpp"

// todo: reset function, clear allowed type every game init
// todo: edit class diagram (cell class)
// todo: function to allow user input (visible)

//-----------Class Board---------------------------------------------------------------------------------------------------
class Board : public Grid{
public:
    //constructor
    Board() = default;

    //todo: make functions override reset
    void reset() override;
    void print() override;

    // todo: function to allow user input (visible)

    uint8_t get(uint8_t x, uint8_t y);                      // todo x, y: min 0, max 8
    void generate();                                        //Methode to generate board
    std::vector<std::vector<uint8_t>> get_board_state();    //Method to get board state

private:
    // not used outside class, no class variables read or changed
    static void convert(uint8_t x, uint8_t y, uint8_t* xb, uint8_t* yb, uint8_t* xc, uint8_t* yc);

    Allowed allowed_x[9];
    Allowed allowed_y[9];

    Block blocks[3][3];     // Composition: A Board is made of Blocks

    File file;
    std::string path = "/Users/lynnmeindertsma/github/sudoku/board_data.txt";
};


#endif //SUDOKU_BOARD_HPP
