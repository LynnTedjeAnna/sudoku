#include "file.hpp"
#include <fstream>
#include <iostream>

void File::save_board(const std::vector<std::vector<uint8_t>>& board_data, const std::string& filename) {
    // Create an output file stream
    std::ofstream output_file(filename);

    if (output_file.is_open()) { // Check if the file was opened successfully
        // Loop through the board data and write it to the file
        for (const auto& row : board_data) {
            for (const auto& cell : row) {
                output_file << static_cast<int>(cell) << " ";
            }
            output_file << "\n"; // Newline after each row
        }
        output_file.close(); // Close the file
        std::cout << "Board data was written to " << filename << "\n";
    } else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
}