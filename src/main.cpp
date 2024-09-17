#include <iostream>
#include <print>
#include "game.hpp"
#include "board.hpp"

// Create instances of the classes
Game game;

int main() {
    // Providing a seed value
    srand((unsigned) time(NULL));

    game.initialize();

    //for(;;);        //infinite loop for debugging

    return 0;
}
