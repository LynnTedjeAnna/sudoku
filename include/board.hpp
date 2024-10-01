//
// Created by Lynn Meindertsma on 02/08/2024.
//

#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <cstdint>
#include "file.hpp"
#include "allowed.hpp"

// todo: reset function, clear allowed type every game init
// todo: edit class diagram (cell class)
// todo: function to allow user input (visible)
 

//-----------Class Cell---------------------------------------------------------------------------------------------------
class Cell {
public:
    // constructor
    Cell() = default;

    //getter and setter
    uint8_t get();
    void set(uint8_t value);
private:
    uint8_t value;
    // todo: differentiate between visible and invisible values!!!
    // todo: notations (possibilities)
};


//-----------Class Block---------------------------------------------------------------------------------------------------
class Block {
public:
    //constructor
    Block() = default;

    //getter and setter
    uint8_t get(uint8_t x, uint8_t y);              // todo x, y: min 0, max 2
    void set(uint8_t x, uint8_t y, uint8_t val);    // todo x, y: min 0, max 2

private:
    Allowed allowed;
    Cell cells[3][3];
    friend class Board;
};

//-----------Class Board---------------------------------------------------------------------------------------------------
class Board {
public:
    //constructor
    Board() = default;

    // todo: function to allow user input (visible)

    uint8_t get(uint8_t x, uint8_t y);                      // todo x, y: min 0, max 8
    void generate();                                        //Methode to generate board
    std::vector<std::vector<uint8_t>> get_board_state();    //Method to get board state
    void print();                                           //Methode to print board

    //uint8_t check_number(uint8_t x, uint8_t y, uint8_t value);
    //bool fill_board(int x, int y);
    //uint8_t random_num_gen();
private:
    // not used outside class, no class variables read or changed
    static void convert(uint8_t x, uint8_t y, uint8_t* xb, uint8_t* yb, uint8_t* xc, uint8_t* yc);

    Allowed allowed_x[9];
    Allowed allowed_y[9];

    Block blocks[3][3];

    File file;
    std::string path = "/Users/lynnmeindertsma/github/sudoku/board_data.txt";
};


#endif //SUDOKU_BOARD_HPP
