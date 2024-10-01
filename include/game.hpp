//
// Created by Lynn Meindertsma on 04/08/2024.
//

#ifndef SUDOKU_GAME_HPP
#define SUDOKU_GAME_HPP
#include "board.hpp"


class Game{
public:
    //constructor
    Game() = default;

    //Methode to start the game
    void initialize();

    void menu();

    //Methode to choose game category
    void category();

private:
    Board board;
};

#endif //SUDOKU_GAME_HPP
