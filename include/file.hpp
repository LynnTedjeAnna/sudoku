//
// Created by Lynn Meindertsma on 17/09/2024.
//

#ifndef SUDOKU_FILE_HPP
#define SUDOKU_FILE_HPP
#include <cstdint>

#include <string>
#include <vector>

class File {
public:
    void save_board(const std::vector<std::vector<uint8_t>>& board_data, const std::string& filename);

private:

};

#endif //SUDOKU_FILE_HPP
