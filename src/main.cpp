#include <iostream>
#include <print>
#include "game.hpp"
#include "board.hpp"

// Create instances of the classes
Game game;

int main() {
    // Providing a seed value
    srand((unsigned) time(NULL));

    Allowed a, b, c;

    a.one = 0;
    a.four = 0;

    b.eight = 0;
    b.nine = 0;

    c.three = 0;
    c.six = 0;

    Allowed res = a & b & c;


    /*
     * for (uint8_t i = 1; i <= 9; i++) {
        printf("%d\n", res.get(i));
        //todo fix
    }
    */
    //for(;;);        //infinite loop for debugging

    game.initialize();
    return 0;
}
