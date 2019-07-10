#include <iostream>

#include "locatable.h"

Locatable::~Locatable()
{
    std::cout << "Destructor of Locatable running" << std::endl;
}

Locatable::Locatable(const int _x, const int _y)
{
    std::cout << "Constructor (int, int) of Locatable running" << std::endl;
    position = Position{_x, _y};
}

[[gnu::pure]]
const Position& Locatable::getPosition() const
{
    return position;
}
