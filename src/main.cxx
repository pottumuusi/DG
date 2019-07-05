#include <iostream>

#include "game.h"

// TODO(pottumuusi) mark gnu::pure functions

Game* doLeak() {
	return new Game();
}

int main() {
    Game game;
    (void) doLeak();
    std::cout << "Hello world!" << std::endl;

    game.init();
    game.test_print();

    return 0;
}
