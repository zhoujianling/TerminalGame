#pragma once
#include <string>

#include "Windows.h"

namespace core {

struct FillCommand {

};

class WindowsTerminal {

public:
    WindowsTerminal();
    ~WindowsTerminal();

    int Initialize();

    void Clear();

    void WriteText(const std::string& text);

    void Fill();

    void Present();

private:
    // HANDLE m_console_handle = nullptr; // stdout

    HANDLE m_buffer_handle = nullptr;

    // CHAR_INFO* m_buffer_front = nullptr;
    CHAR_INFO* m_buffer_back = nullptr;

    COORD m_buffer_size;

};


}