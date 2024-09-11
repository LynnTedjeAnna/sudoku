//
// Created by Lynn Meindertsma on 04/08/2024.
//
#include <print>
#include "game.hpp"
#include "board.hpp"

// Create instances of the classes
Board board;

void Game::initialize() {
    do {
        printf("Welcome to sudoku \n");
        //category(); //todo: functionality later
        board.print();

    } while (end());                                //loop until you want to end game
    printf("Thank you for playing :)");
}
//todo: finish later in project
void Game::category() {
    //todo: make difficulty categories, easy, medium, hard
    //later maybe different kind of sudoku games
    //todo: use category variable for game

    do {
        printf("\nChoose your game category: \n"
               "1) easy\n"
               "2) medium\n"
               "3) hard\n"
        );
        scanf("%d", &choice);
    } while (choice >= 4);        //loop if choice is not possible
}

uint8_t Game::end() {
    //todo: add time to completion/failure?
    uint32_t replay = 0;
    do {
        printf("Do you want to play another game?\n"
               "0) no\n"
               "1) yes\n");
        scanf("%d", &replay);
    } while (replay > 1);                           //loop if choice is not possible
    return replay != 0;
}