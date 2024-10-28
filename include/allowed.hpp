//
// Created by Lynn Meindertsma on 30/09/2024.
//

#ifndef SUDOKU_ALLOWED_HPP
#define SUDOKU_ALLOWED_HPP
#include <cstdint>

//todo: setter and getter allowed

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
    Allowed& operator=(uint16_t data) {
        *((uint16_t*)(this)) = data;
        return *this;
    }*/

    Allowed& operator=(Allowed& other) = default;
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

    void clear_allowed() {
        // Set all bits to 1 (all allowed)
        *((uint16_t*)this) |= 0xFFFF;
    }

    // Setter to allow or disallow a specific digit (1-9)
    void set(uint8_t num, bool if_allowed) {
        if (num < 1 || num > 9) return;  // Invalid number

        uint16_t mask = (1 << (num - 1));
        if (if_allowed) {
            *((uint16_t*)this) |= mask;  // Set the bit to 1
        } else {
            *((uint16_t*)this) &= ~mask;  // Clear the bit
        }
    }

    // Getter to check if a specific digit (1-9) is allowed
    bool is_allowed(uint8_t num) const {
        if (num < 1 || num > 9) return false;  // Invalid number

        uint16_t mask = (1 << (num - 1));
        return *((uint16_t*)this) & mask;
    }

    uint8_t random_allowed() {
        uint16_t data = *((uint16_t*)this);
        if (!(data & 0b111111111)) { return -1; }   // nothing allowed
        uint8_t num;
        do {
            num = (rand() % 9);
        } while (!(data & (1 << num)));             // todo: use getter here!!
        return num + 1;
    }

};


#endif //SUDOKU_ALLOWED_HPP
