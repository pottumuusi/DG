#ifndef GAME_H_DEFINED
#define GAME_H_DEFINED

#include <vector>

#include "actor.h"

class Game {
public:
    Game() = delete;
    ~Game();
    Game(bool _is_interactive);

    void init();
    void test_print() const;

    bool get_is_interactive() const;

private:
    std::vector<Actor> actors;
    bool is_interactive;
};

#endif // GAME_H_DEFINED
