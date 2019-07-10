#include <iostream>

#include "position.h"

Position::~Position()
{
    std::cout << "Destructor of Position running" << std::endl;
}

Position::Position(int _x, int _y)
    : x{_x}, y{_y}
{
    std::cout << "Constructor (int, int) of Position running" << std::endl;
}

[[gnu::pure]]
int Position::getX() const
{
    return x;
}

[[gnu::pure]]
int Position::getY() const
{
    return y;
}
