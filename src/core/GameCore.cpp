#include "GameCore.h"

#include "Input.h"
#include "TerminalController.h"
#include "../gameplay/Game.h"

#include <iostream>
#include <thread>
#include <chrono>

namespace core {

    GameCore::GameCore() {}
    GameCore::~GameCore() {}

    void GameCore::Run() {
        using namespace std::chrono_literals;
        while (true) {

            TickModel();
            TickView();

            // std::this_thread::yield();
            // todo: ...
            std::this_thread::sleep_for(16ms);
        }

    }

    void GameCore::Initialize() {
        m_input.reset(new KeyboardInput);
        m_terminal.reset(new TerminalController);

    }

    void GameCore::CreateGame() {
        m_game.reset(new game::Game);
        m_game->m_core = this;
    }

    void GameCore::TickModel() {
        m_input->CollectInput();
        m_game->Tick(0.17f);
    }

    void GameCore::TickView() {
        m_terminal->Tick(0.17f);
    }

}
