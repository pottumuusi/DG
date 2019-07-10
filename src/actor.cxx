#include <iostream>

#include "actor.h"

Actor::~Actor()
{
    std::cout << "Destructor of Actor running" << std::endl;
}

Actor::Actor(std::string _name)
    : name{std::move(_name)}
    , Locatable{-1, -1}
{
    std::cout << "Constructor (std::string) of Actor (" << _name << ") running" << std::endl;
}

Actor::Actor(std::string _name, const int _x, const int _y)
    : name{std::move(_name)}
    , Locatable{_x, _y}
{
    std::cout << "Constructor (std::string, int, int) of Actor (" << _name << ") running" << std::endl;
}

[[gnu::pure]]
std::string Actor::getName() const
{
    return name;
}
