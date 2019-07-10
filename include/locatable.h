#ifndef LOCATABLE_H_DEFINED
#define LOCATABLE_H_DEFINED

#include "position.h"

class Locatable {
public:
    Locatable() = delete;
    ~Locatable();
    Locatable(const int _x, const int _y);
    const Position& getPosition() const;
private:
    Position position;
};

#endif // LOCATABLE_H_DEFINED
