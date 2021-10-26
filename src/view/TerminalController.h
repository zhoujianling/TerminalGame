#pragma once
#include "../core/ITickable.h"
#include "Terminal.h"
#include "Element.h"
#include <chrono>
#include <vector>


namespace scene {
    class Scene;
    class Sprite;
}

namespace core {
    class Game;
    class GameCore;

class TerminalController : public ITickable {
    friend class GameCore;
public:
    TerminalController();
    ~TerminalController() override;

    void Tick(float delta_time) override;

private:

    void Draw();

    void DrawGame(core::Game* game);

    void DrawScene(scene::Scene& scene);

    void DrawSprite(scene::Sprite* sprite);

    void FillScreen();

private:
    WindowsTerminal m_terminal;    

    int m_char_count = 0;

    std::chrono::system_clock::duration m_init_time;

    std::vector<ScreenElement> m_elements;

    GameCore* m_core = nullptr;

};

}