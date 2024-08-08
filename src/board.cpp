//
// Created by Lynn Meindertsma on 02/08/2024.
//

#include "board.hpp"
#include "print"

uint8_t Block::get(uint8_t x, uint8_t y) { return this->cells[x][y]; }
void Block::set(uint8_t x, uint8_t y, uint8_t val) { this->cells[x][y] = val; }

void Board::print() {
    uint8_t block_x;
    uint8_t block_y;
    uint8_t cell_x;
    uint8_t cell_y;

    // Print the top border of the board
    printf("\n  —————————————————————————————————\n");

    // Loop through each row of the board
    for (int y = 0; y < 9; ++y) {
        // Print a horizontal divider between blocks, except at the very top
        if (!(y % 3) && y) {
            printf("  —————————————————————————————————\n");
        }

        // Loop through each column of the board
        for (int x = 0; x < 9; ++x) {
            // Convert the (x, y) coordinates to block and cell coordinates
            convert(x, y, &block_x, &block_y, &cell_x, &cell_y);

            // Print a vertical divider between blocks
            if (!(x % 3)) {
                printf("  |  ");
            }

            // Get the value of the cell at the converted coordinates
            uint8_t value = blocks[block_x][block_y].get(cell_x, cell_y);

            // Print the value of the cell
            printf("%d ", value);
        }
        printf(" | \n");
    }
    printf("  —————————————————————————————————\n");
}


void Board::convert(uint8_t x, uint8_t y, uint8_t* xb, uint8_t* yb, uint8_t* xc, uint8_t* yc) {
    *xb = x / 3;  // Determine the block number in the x-direction (0, 1, or 2)
    *yb = y / 3;  // Determine the block number in the y-direction (0, 1, or 2)

    *xc = x % 3;   // Determine the cell number within the block in the x-direction (0, 1, or 2)
    *yc = y % 3;   // Determine the cell number within the block in the y-direction (0, 1, or 2)
}