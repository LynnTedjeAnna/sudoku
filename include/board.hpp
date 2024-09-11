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

    uint8_t get(uint8_t index) {
        //todo: if index > 8...
        uint16_t data = *((uint16_t*)this);
        // first index is 0
        return (data >> index) & 1;                         // Shift right by 'index' and mask with 1 to get the bit at 'index'
    }

    void set(uint8_t index, uint8_t val) {
        uint16_t data = *((uint16_t*)this);                 // Read the current 16-bit value from the object
        data = ((data & ~(1 << index)) | (val << index));   // Clear the bit at the specified index and then set it to 'val'
        *((uint16_t*)this) = data;                          //Write the modified value back to the object's memory
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

    //Methode to generate board
    void generate();

private:
    Block blocks[3][3];
};


#endif //SUDOKU_BOARD_HPP
