#include "TerminalController.h"
#include <cstdlib>
#include <iostream>

namespace core {


TerminalController::TerminalController() {
    m_terminal.Initialize();

    m_init_time = std::chrono::system_clock::now().time_since_epoch();
}

TerminalController::~TerminalController() {
}

void TerminalController::Tick(float delta_time) {
    Draw();

    m_terminal.Present();
}

void TerminalController::Draw() {
    m_terminal.Clear();

    const auto curr_time = std::chrono::system_clock::now().time_since_epoch();

    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>((curr_time - m_init_time)).count();
    auto text = std::string("curr time is ") + std::to_string(millis / 1000.0f); 

    m_terminal.WriteText(text);
}

}