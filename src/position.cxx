#include <iostream>

// TODO Use a less fragile way for inclusion
#include "../include/position.h"

Position::Position() : x{-1}, y{-1} {
    std::cout << "Default constructor of Position running" << std::endl;
}

Position::~Position() {
    std::cout << "Destructor of Position running" << std::endl;
}

Position::Position(int _x, int _y) : x{_x}, y{_y} {
    std::cout << "Constructor (int, int) of Position running" << std::endl;
}
