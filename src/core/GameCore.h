#pragma once

#include <memory>
#include "Input.h"
#include "TerminalController.h"

namespace game {
    class Game;
}

namespace core {

    class KeyboardInput;
    class TerminalController;

class GameCore {

public:
    void Run();

    void Initialize();

    void CreateGame();

    game::Game* GetGame() { return m_game.get(); }

private:
    void TickModel();

    void TickView();

private:
    int m_frame_rate;

    std::unique_ptr<KeyboardInput> m_input;
    std::unique_ptr<TerminalController> m_terminal;

    std::unique_ptr<game::Game> m_game;

};

}