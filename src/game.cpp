//
// Created by Lynn Meindertsma on 04/08/2024.
//
#include <print>
#include "game.hpp"
#include "board.hpp"

//todo: all ui in game class

void Game::start() {
    printf("welcome to sudoku \n");

}

void Game::initialize() {


    //category(); //todo: functionality later
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


//todo: make bool?
void Game::end() {
    //todo: add time to completion/failure?
    do {
        printf("Do you want to play another game?\n"
               "1) yes\n"
               "2) no\n");
        scanf("%d", &replay);
    } while (replay >= 3);            //loop if choice is not possible
    if (replay == 1){ initialize();}
    if (replay == 2){ return; }
}