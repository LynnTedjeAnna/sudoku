//
// Created by Lynn Meindertsma on 02/08/2024.
//

#include <ncurses.h>
#include <iostream>
#include "board.hpp"

//todo: make interactive board

uint8_t Board::get(uint8_t x, uint8_t y) {
    uint8_t block_x, block_y, cell_x, cell_y;
    convert(x, y, &block_x, &block_y, &cell_x, &cell_y);
    return blocks[block_x][block_y].get(cell_x, cell_y);
}

void Board::generate() {
    //clear all allowed types, set to 0xFF
    for (uint8_t i = 0; i < 9; i++) {
        allowed_x[i].clear_allowed();
        allowed_y[i].clear_allowed();
    }
    for (uint8_t y = 0; y < 3; y++) {
        for (uint8_t x = 0; x < 3; x++) {
            blocks[x][y].allowed.clear_allowed();
        }
    }
    
    for (uint8_t y = 0; y < 9; y++) {
        for (uint8_t x = 0; x < 9; x++) {
            uint8_t yb, xb, yc, xc;
            convert(x, y, &xb, &yb, &xc, &yc);
            Allowed allowed = blocks[xb][yb].allowed & allowed_x[x] & allowed_y[y];
            uint8_t num = allowed.random_allowed();

            if (num == 0xFF){           //if return false(-1), unsigned->255 (FF)
                //print();
                std::cerr << "\nYou made a big mistake :(\n";       ///exception
                return generate();
            }

            blocks[xb][yb].allowed.set(num, 0);
            allowed_x[x].set(num, 0);
            allowed_y[y].set(num, 0);

            blocks[xb][yb].set(xc, yc, num);
        }
    }

    print();
    file.save_board(get_board_state(), path);           //streams
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

void Board::reset() {
    //todo
}
