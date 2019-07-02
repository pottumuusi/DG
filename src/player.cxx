#include <iostream>

// TODO(pottumuusi) Use a less fragile way to include
#include "../include/player.h"

Player::Player() {
    std::cout << "Default constructor of Player running" << std::endl;
}

Player::~Player() {
    std::cout << "Constructor of Player running" << std::endl;
}

// TODO(pottumuusi) expand so that Locatable constructor is called with position
Player::Player(std::string _name) : Actor{std::move(_name)} {
    std::cout << "Constructor (string) of Player running" << std::endl;
}
