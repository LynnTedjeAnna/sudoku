//
// Created by Lynn Meindertsma on 04/08/2024.
//

#ifndef SUDOKU_GAME_HPP
#define SUDOKU_GAME_HPP


class Game{
public:
    //constructor
    Game() = default;

    //Methode to start the game
    void initialize();

    void menu();

    //Methode to choose game category
    void category();

    //Methode to end the game
    uint8_t end();

private:
    uint8_t choice; //variable for game category input
};

#endif //SUDOKU_GAME_HPP
