//
// Created by Lynn Meindertsma on 10/10/2024.
//
#include "cell.hpp"

uint8_t Cell::get() {
    return this->value;
}
void Cell::set(uint8_t val) {
    this->value = val;
}
