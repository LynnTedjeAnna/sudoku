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

    //todo if return false(-1) do something were called, unsigned->255 (FF)
    uint8_t random_allowed() {
        uint16_t data = *((uint16_t*)this);
        if (!(data & 0b111111111)) { return -1; }   // nothing allowed
        uint8_t num;
        do {
            num = (rand() % 9) + 1;
        } while (!(data & (1 << num)));             // todo: use getter here!!
        return num;
    }
};


#endif //SUDOKU_ALLOWED_HPP
