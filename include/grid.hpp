//
// Created by Lynn Meindertsma on 13/10/2024.
//

#ifndef SUDOKU_GRID_HPP
#define SUDOKU_GRID_HPP

class Grid{
public:
    //constructor
    Grid() = default;
    virtual void reset() = 0; // Pure virtual function
    virtual void print() = 0; // Pure virtual function

private:

};
#endif //SUDOKU_GRID_HPP
