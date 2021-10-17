#pragma once
#include "ITickable.h"
#include "Terminal.h"
// #include "TerminalBuffer.h"
#include <chrono>

namespace core {

class TerminalController : public ITickable {

public:
    TerminalController();
    ~TerminalController() override;

    void Tick(float delta_time) override;

private:

    void Draw();

private:
    WindowsTerminal m_terminal;    

    int m_char_count = 0;

    // TerminalBuffer m_buffer;

    std::chrono::system_clock::duration m_init_time;

};

}