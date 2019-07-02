#include <iostream>

#include "../include/game.h"

// TODO mark gnu::pure functions

int main() {
    Game game;
    std::cout << "Hello world!" << std::endl;

    game.init();
    game.test_print();

    return 0;
}
