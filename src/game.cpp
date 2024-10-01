//
// Created by Lynn Meindertsma on 04/08/2024.
//
#include <print>
#include "game.hpp"
#include <ncurses.h>



void Game::initialize() {
    printf("Welcome to sudoku \n");
    menu();     //todo: functionality different difficulties
}

void Game::menu() {
    uint8_t choice; //variable for game category input
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
