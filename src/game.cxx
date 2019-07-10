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
    const int p2_x = 10;
    const int p2_y = 20;
    Player player1("Player 1");
    Player player2("Player 2", p2_x, p2_y);
    std::cout << "Game init running" << std::endl;

    // TODO(pottumuusi) change to use references
    actors.push_back(player1);
    actors.push_back(player2);
}

void Game::test_print() const {
    std::cout << "Name of actors[0] is: " << actors[0].getName() << std::endl;
    std::cout << "Name of actors[1] is: " << actors[1].getName() << std::endl;
    std::cout << "Coordinates of actors[1] is: ("
        << actors[1].getPosition().getX()
        << ", "
        << actors[1].getPosition().getY()
        << ")" << std::endl;
}
