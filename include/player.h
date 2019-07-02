#ifndef PLAYER_H_DEFINED
#define PLAYER_H_DEFINED

#include "locatable.h"
#include "actor.h"

class Player : public Actor, public Locatable {
public:
    Player();
    ~Player();
    Player(std::string _name);

private:
};

#endif // PLAYER_H_DEFINED
