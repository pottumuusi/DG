#include <iostream>

#include "player.h"

Player::~Player()
{
    std::cout << "Constructor of Player running" << std::endl;
}

Player::Player(std::string _name)
    : Actor{std::move(_name)}
{
    std::cout << "Constructor (string) of Player running" << std::endl;
}

Player::Player(std::string _name, const int _x, const int _y)
    : Actor{std::move(_name), _x, _y}
{
}
