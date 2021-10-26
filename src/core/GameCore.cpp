#include "GameCore.h"

#include "Input.h"
#include "Game.h"
#include "../view/TerminalController.h"

#include <iostream>
#include <thread>
#include <chrono>
#include "assert.h"

namespace core {

    static GameCore* m_active_instance = nullptr;

    GameCore::GameCore() {}

    GameCore::~GameCore() {
        if (m_active_instance == this) {
            m_active_instance = nullptr;
        }
    }

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

        m_terminal->m_core = this;

        assert(m_active_instance == nullptr);
        m_active_instance = this;
    }

    void GameCore::CreateGame() {
        m_game.reset(new Game);
        m_game->m_core = this;
    }

    GameCore* GameCore::GetInstance() {
        return m_active_instance;
    }

    void GameCore::TickModel() {
        m_input->CollectInput();
        auto* game = m_game.get();
        if (game) {
            game->Tick(0.17f);
        }
    }

    void GameCore::TickView() {
        m_terminal->Tick(0.17f);
    }

}
