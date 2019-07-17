#include <iostream>
#include <vector>

#include "game.h"

// TODO(pottumuusi) mark gnu::pure functions

struct run_cfg
{
    bool interactive = true;
};

void process_args(const std::vector<std::string>& args, struct run_cfg* cfg)
{
    std::string nointeractive_f = "--nointeractive";

    for (const std::string& arg : args) {
        if (nointeractive_f == arg) {
            cfg->interactive = false;
            continue;
        }
    }
}

int main(int argc, char* argv[]) {
    struct run_cfg cfg;
    std::cout << "Hello world!" << std::endl;
    std::vector<std::string> args;

    for (int i = 1; i < argc; i++) {
        args.emplace_back(argv[i]); // NOLINT, pointer arithmetic
    }

    if (argc > 1) {
        process_args(args, &cfg);

        std::cout << "args size is: " << args.size() << std::endl;
    }

    Game game(cfg.interactive);
    game.init();
    game.test_print();
// TODO(#28) Add deinit to game
#if 0
    game.deinit();
#endif

    return 0;
}
