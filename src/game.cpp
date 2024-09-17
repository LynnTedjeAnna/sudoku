//
// Created by Lynn Meindertsma on 04/08/2024.
//
#include <print>
#include "game.hpp"
#include "board.hpp"

// Create instances of the classes
Board board;

//todo:simplify initialize function
void Game::initialize() {

    printf("Welcome to sudoku \n");
    menu(); //todo: functionality different difficulties later
}

void Game::menu() {
    do {
        printf("\nChoose your game category: \n"
               "1) easy\n"
               "2) medium\n"
               "3) hard\n"
               "0) quit\n"
        );
        scanf("%d", &choice);
    } while (choice >  3);        //loop if choice is not possible
    switch (choice) {
        case 0:
            printf("Thank you for playing :)");
            break;
        case 1:
            board.generate();       //todo different cat
            break;
        case 2:
            board.generate();       //todo different cat
            break;
        case 3:
            board.generate();       //todo different cat
            break;
        default:
            break;
    }
}

//todo: finish later in project
void Game::category() {
    /* todo: make difficulty categories, easy, medium, hard
     * later maybe different kind of sudoku games
     * use category variable for game
    */
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