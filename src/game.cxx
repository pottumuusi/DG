#include <iostream>

#include "../include/game.h"
#include "../include/player.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init() {
    Player player("Player 1");
    std::cout << "Game init running" << std::endl;

    // TODO change to use references
    actors.push_back(player);
}

void Game::test_print() {
    std::cout << "Name of actors[0] is: " << actors[0].getName() << std::endl;
}
