//
// Created by Lynn Meindertsma on 10/10/2024.
//

#include "block.hpp"
uint8_t Block::get(uint8_t x, uint8_t y) { return this->cells[x][y].get(); }
void Block::set(uint8_t x, uint8_t y, uint8_t val) { this->cells[x][y].set(val); }

void Block::print() {

    // Print the top border of the board
    printf("\n —————————\n");

    // Loop through each row of the block
    for (uint8_t y = 0; y < 3; ++y) {

        printf(" | ");

        // Loop through each column of the block
        for (uint8_t x = 0; x < 3; ++x) {

            uint8_t value = get(x, y);

            // Print the value of the cell
            printf("%d ", value);
        }
        printf(" | \n");
    }
    printf(" —————————\n");

}

void Block::reset() {
    //todo
}
