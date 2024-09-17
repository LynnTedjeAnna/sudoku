//
// Created by Lynn Meindertsma on 02/08/2024.
//

#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP
#include <cstdint>

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
    void print();
    void convert(uint8_t x, uint8_t y, uint8_t* xb, uint8_t* yb, uint8_t* xc, uint8_t* yc);

    uint8_t get(uint8_t x, uint8_t y);
    void set(uint8_t x, uint8_t y, uint8_t val);

    //Methode to generate board
    void generate();

    uint8_t check_number(uint8_t x, uint8_t y, uint8_t value);

    bool fill_board(int x, int y);


private:
    Block blocks[3][3];
    uint8_t random_number;
};


#endif //SUDOKU_BOARD_HPP
