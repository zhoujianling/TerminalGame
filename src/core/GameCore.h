#pragma once

#include <memory>

namespace view {

}

namespace core {

    class Game;
    class KeyboardInput;
    class TerminalController;

class GameCore {

public:
    GameCore();
    ~GameCore();

    void Run();

    void Initialize();

    void CreateGame();

    Game* GetGame() { return m_game.get(); }

    KeyboardInput* GetInput() { return m_input.get(); }

    static GameCore* GetInstance();

private:
    void TickModel();

    void TickView();

private:
    int m_frame_rate;

    std::unique_ptr<KeyboardInput> m_input;
    std::unique_ptr<TerminalController> m_terminal;

    std::unique_ptr<Game> m_game;


};

}