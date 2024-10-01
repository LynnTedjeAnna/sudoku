//
// Created by Lynn Meindertsma on 02/08/2024.
//

#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include "board.hpp"
#include <ncurses.h>
#include "print"

//todo: save boards, for future use & to look back
//todo: make interactive board

//todo if return false(-1) do something were in board called
// uint8_t random_allowed()

//todo: make clear function for allowed type, insert in function
// todo: create disallow function allowed type, what cannot be filled
//todo: fix allowed type, change value of allowed after num gen set


//-----------Class Cell---------------------------------------------------------------------------------------------------
uint8_t Cell::get() {
    return this->value;
}
void Cell::set(uint8_t val) {
    this->value = val;
}


//-----------Class Block---------------------------------------------------------------------------------------------------
uint8_t Block::get(uint8_t x, uint8_t y) { return this->cells[x][y].get(); }
void Block::set(uint8_t x, uint8_t y, uint8_t val) { this->cells[x][y].set(val); }


//-----------Class Board---------------------------------------------------------------------------------------------------
uint8_t Board::get(uint8_t x, uint8_t y) {
    uint8_t block_x, block_y, cell_x, cell_y;
    convert(x, y, &block_x, &block_y, &cell_x, &cell_y);
    return blocks[block_x][block_y].get(cell_x, cell_y);
}


void Board::generate() {
    //todo: make clear function allowed type, insert in function

    // todo: create disallow function allowed type, what cannot be filled

    for (uint8_t y = 0; y < 9; y++) {
        for (uint8_t x = 0; x < 9; x++) {
            uint8_t yb, xb, yc, xc;
            convert(x, y, &xb, &yb, &xc, &yc);
            Allowed allowed = blocks[xb][yb].allowed & allowed_x[x] & allowed_y[y];
            uint8_t num = allowed.random_allowed();

            //todo: fix allowed type, change value of allowed after num gen set

            blocks[xb][yb].set(xc, yc, num);
        }
    }
}

std::vector<std::vector<uint8_t>> Board::get_board_state() {
    std::vector<std::vector<uint8_t>> board_state(9, std::vector<uint8_t>(9, 0)); // 9x9 board
    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            board_state[x][y] = get(x, y); // Get the value from the board and store it in the vector
        }
    }
    return board_state;
}

void Board::print() {
    uint8_t block_x, block_y, cell_x, cell_y;

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


