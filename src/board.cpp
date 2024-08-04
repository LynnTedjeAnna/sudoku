//
// Created by Lynn Meindertsma on 02/08/2024.
//

#include "board.hpp"


uint8_t Block::get(uint8_t x, uint8_t y) { return this->cells[x][y]; }
void Block::set(uint8_t x, uint8_t y, uint8_t val) { this->cells[x][y] = val; }

