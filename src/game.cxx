#include <iostream>

#include "game.h"
#include "player.h"

Game::Game() {
    std::cout << "Default constructor of Game running" << std::endl;
}

Game::~Game() {
    std::cout << "Destructor of Game running" << std::endl;
}

void Game::init() {
    Player player("Player 1");
    std::cout << "Game init running" << std::endl;

    // TODO(pottumuusi) change to use references
    actors.push_back(player);
}

void Game::test_print() const {
    std::cout << "Name of actors[0] is: " << actors[0].getName() << std::endl;
}
