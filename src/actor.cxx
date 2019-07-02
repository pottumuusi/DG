#include <iostream>

#include "../include/actor.h"

// TODO Do not allow to construct without name
Actor::Actor() {
    std::cout << "Default constructor of Actor running" << std::endl;
}

Actor::~Actor() {
    std::cout << "Destructor of Actor running" << std::endl;
}

Actor::Actor(std::string _name) : name{_name} {
}

std::string Actor::getName() {
    return name; // TODO see if need for optimization
}
