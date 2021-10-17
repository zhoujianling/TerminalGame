#include <iostream>
#include "core/GameCore.h"


int main(int argc, const char** argv) {
    // std::cout << "hello " << std::endl;
    core::GameCore game_core;
    game_core.Initialize();
    game_core.Run();
    return 0;
}