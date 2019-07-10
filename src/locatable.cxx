#include <iostream>

#include "locatable.h"

Locatable::~Locatable()
{
    std::cout << "Destructor of Locatable running" << std::endl;
}

Locatable::Locatable(const int _x, const int _y)
    : position{_x, _y}
{
    std::cout << "Constructor (int, int) of Locatable running" << std::endl;
}

[[gnu::pure]]
const Position& Locatable::getPosition() const
{
    return position;
}
