//
// Created by Lynn Meindertsma on 04/08/2024.
//
#include <print>
#include "game.hpp"
#include "board.hpp"

void Game::start() {
    initialize();
    end();
}

void Game::initialize() {
    printf("welcome to sudoku \n");
    game_cat(); //todo: functionality
    //todo
}

void Game::game_cat() {
    //todo: make difficulty categories, easy, medium, hard
    //later maybe different kind of sudoku games
    do {
        printf("\nChoose your game category: \n"
               "1) easy\n"
               "2) medium\n"
               "3) hard\n"
        );
        scanf("%d", &category);
    } while (category >= 4);        //loop if choice is not possible
}
//todo: use category variable for game

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