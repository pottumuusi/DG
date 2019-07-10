#ifndef PLAYER_H_DEFINED
#define PLAYER_H_DEFINED

#include "locatable.h"
#include "actor.h"

class Player : public Actor {
public:
    Player() = delete;
    ~Player();
    Player(std::string _name);
    Player(std::string _name, const int _x, const int _y);

private:
};

#endif // PLAYER_H_DEFINED
