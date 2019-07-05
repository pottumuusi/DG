#include <iostream>

#include "actor.h"

// TODO(pottumuusi) Do not allow to construct without name
Actor::Actor() {
    std::cout << "Default constructor of Actor running" << std::endl;
}

Actor::~Actor() {
    std::cout << "Destructor of Actor running" << std::endl;
}

Actor::Actor(std::string _name) : name{std::move(_name)} {
}

[[gnu::pure]]
std::string Actor::getName() const {
    return name;
}
