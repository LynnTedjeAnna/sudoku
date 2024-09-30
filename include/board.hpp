//
// Created by Lynn Meindertsma on 02/08/2024.
//

#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <cstdint>
#include "file.hpp"

//todo: edit class diagram (cell class)
//-----------Class Allowed---------------------------------------------------------------------------------------------------

class Allowed {
public:
    uint16_t one    : 1;
    uint16_t two    : 1;
    uint16_t three  : 1;
    uint16_t four   : 1;
    uint16_t five   : 1;
    uint16_t six    : 1;
    uint16_t seven  : 1;
    uint16_t eight  : 1;
    uint16_t nine   : 1;

    /* prettiness code
    operator uint16_t () const { return *((uint16_t*)this); }
    Allowed& operator=(Allowed& other) = default;
    Allowed& operator=(uint16_t data) {
        *((uint16_t*)(this)) = data;
        return *this;
    }*/

    Allowed(void) {
        // 'this' is a pointer to the current instance of Allowed
        // '(uint16_t*)' casts the 'this' pointer to allow the data of this instance to be manipulated as an uint16_t
        *((uint16_t*)this) = 0xFFFF;
    }
    Allowed operator&(Allowed other) {
        Allowed res;
        uint16_t th = *((uint16_t*)this);
        uint16_t ot = *((uint16_t*)(&other));
        *((uint16_t*)(&res)) = th & ot;
        return res;
    }
};

//-----------Class Cell---------------------------------------------------------------------------------------------------

//todo: 9 possibilities, one allowed type for what's possible in cell
class Cell {
public:
    Cell() = default;

    uint16_t get();

private:
};

//-----------Class Block---------------------------------------------------------------------------------------------------

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

//-----------Class Board---------------------------------------------------------------------------------------------------

class Board {
public:
    //constructor
    Board() = default;

    void print();                                           //Methode to print board
    void convert(uint8_t x, uint8_t y, uint8_t* xb, uint8_t* yb, uint8_t* xc, uint8_t* yc);
    uint8_t get(uint8_t x, uint8_t y);
    void set(uint8_t x, uint8_t y, uint8_t val);
    void generate();                                        //Methode to generate board
    std::vector<std::vector<uint8_t>> get_board_state();    //Method to get board state
    uint8_t check_number(uint8_t x, uint8_t y, uint8_t value);
    bool fill_board(int x, int y);

    //todo
    uint8_t random_num_gen();

private:
    Allowed allowed_x1;
    Allowed allowed_x2;
    Allowed allowed_x3;
    File file;
    Block blocks[3][3];
    std::string path = "/Users/lynnmeindertsma/github/sudoku/board_data.txt";
};


#endif //SUDOKU_BOARD_HPP
