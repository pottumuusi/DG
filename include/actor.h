#ifndef ACTOR_H_DEFINED
#define ACTOR_H_DEFINED

#include <string>

#include "locatable.h"

class Actor : public Locatable {
public:
    Actor() = delete;
    ~Actor();
    Actor(std::string);
    Actor(std::string, const int _x, const int _y);

    std::string getName() const;

private:
    std::string name;
};

#endif // ACTOR_H_DEFINED
