#include <iostream>
#include <ncurses.h>

#include "game.h"
#include "player.h"

Game::~Game()
{
    std::cout << "Destructor of Game running" << std::endl;
}

Game::Game(bool _is_interactive) : is_interactive{_is_interactive}
{
}

void Game::init()
{
    const int p2_x = 10;
    const int p2_y = 20;
    std::string hello = "Hello World!";
    Player player1("Player 1");
    Player player2("Player 2", p2_x, p2_y);
    std::cout << "Game init running" << std::endl;

    initscr();
    printw(hello.c_str()); // NOLINT, c-style vararg function
    refresh();
    if (get_is_interactive()) {
        getch();
    }
    endwin();

    // TODO(pottumuusi) change to use references
    actors.push_back(player1);
    actors.push_back(player2);
}

// TODO(#28) Add deinit to game
#if 0
void Game::deinit() {
    endwin();
}
#endif

void Game::test_print() const
{
    std::cout << "Name of actors[0] is: " << actors[0].getName() << std::endl;
    std::cout << "Name of actors[1] is: " << actors[1].getName() << std::endl;
    std::cout << "Coordinates of actors[1] is: ("
        << actors[1].getPosition().getX()
        << ", "
        << actors[1].getPosition().getY()
        << ")" << std::endl;
}

bool Game::get_is_interactive() const
{
    return is_interactive;
}
