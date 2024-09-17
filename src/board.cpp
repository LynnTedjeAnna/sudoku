//
// Created by Lynn Meindertsma on 02/08/2024.
//

#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include "board.hpp"
#include "print"

//todo: make interactive board

uint8_t Block::get(uint8_t x, uint8_t y) { return this->cells[x][y]; }
void Block::set(uint8_t x, uint8_t y, uint8_t val) { this->cells[x][y] = val; }

uint8_t Board::get(uint8_t x, uint8_t y) {
    uint8_t block_x, block_y, cell_x, cell_y;
    convert(x, y, &block_x, &block_y, &cell_x, &cell_y);
    return blocks[block_x][block_y].get(cell_x, cell_y);
}
void Board::set(uint8_t x, uint8_t y, uint8_t val) {
    uint8_t block_x, block_y, cell_x, cell_y;
    convert(x, y, &block_x, &block_y, &cell_x, &cell_y);
    blocks[block_x][block_y].set(cell_x, cell_y, val);
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

void Board::generate() {
    // Clear the board by setting all cells to 0
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            set(x, y, 0);
        }
    }

    // Call the recursive function to fill the board
    fill_board(0, 0);
    print();
}

bool Board::fill_board(int x, int y) {
    // Move to the next row all columns are filled
    if (x == 9) {
        x = 0;
        y++;
        // When all rows are filled, the board is complete
        if (y == 9) {
            return true;
        }
    }

    // Try to place numbers 1 to 9 in the current cell
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // A random number generator
    std::random_device rd;
    std::default_random_engine rng(rd());

    // Shuffle the numbers
    std::shuffle(nums.begin(), nums.end(), rng);

    for (int i = 0; i < 9; i++) {
        int value = nums[i];
        if (check_number(x, y, value)) {
            set(x, y, value);

            // Recursively attempt to fill the rest of the board
            if (fill_board(x + 1, y)) {
                return true;
            }

            // If it fails, reset the cell
            set(x, y, 0);
        }
    }

    // If no number fits, return false to trigger backtracking
    return false;
}

uint8_t Board::check_number(uint8_t x, uint8_t y, uint8_t value) {
    // Use convert to get block and cell indices
    uint8_t block_x, block_y, cell_x, cell_y;
    convert(x, y, &block_x, &block_y, &cell_x, &cell_y);

    // Check for duplicates in the row
    for (int i = 0; i < 9; i++) {
        if (get(i, y) == value) {
            return 0;
        }
    }

    // Check for duplicates in the column
    for (int i = 0; i < 9; i++) {
        if (get(x, i) == value) {
            return 0;
        }
    }

    // Check for duplicates within the block
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (blocks[block_x][block_y].get(i, j) == value) {
                return 0;
            }
        }
    }

    return 1; // No duplicates found; number is valid
}












