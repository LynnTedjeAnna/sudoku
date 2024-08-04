//
// Created by Lynn Meindertsma on 04/08/2024.
//

#ifndef SUDOKU_GAME_HPP
#define SUDOKU_GAME_HPP


class Game{
public:
    //constructor
    Game() = default;

    //Methode for game
    void start();

    //Methode to start the game
    void initialize();

    //Methode to choose game category
    void game_cat();

    //Methode to end the game
    void end();

private:
    uint32_t category; //variable for game category input
    uint32_t replay; //variable for to replay

};

#endif //SUDOKU_GAME_HPP
