#ifndef GAME_H_DEFINED
#define GAME_H_DEFINED

#include <vector>

#include "actor.h"

class Game {
public:
    Game();
    ~Game();

    void init();
    void test_print() const;

private:
    std::vector<Actor> actors;
};

#endif // GAME_H_DEFINED
