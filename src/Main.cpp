#include <iostream>
#include "core/GameCore.h"

// ###
#include "TankGame.h"
// ###

int main(int argc, const char** argv) {
    // std::cout << "hello " << std::endl;
    core::GameCore game_core;
    game_core.Initialize();

    // ------------------------
    TankGame tank_game;
    tank_game.MakeGame(& game_core);
    // ------------------------

    game_core.Run();

    return 0;
}