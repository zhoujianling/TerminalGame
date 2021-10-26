#include "Terminal.h"
#include "assert.h"
#include "../core/Common.h"

namespace core {


WindowsTerminal::WindowsTerminal() {
    // m_console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

WindowsTerminal::~WindowsTerminal() {
    SafeRelease(m_buffer_handle);    
    // SafeReleaseArray(m_buffer_front);    
    SafeReleaseArray(m_buffer_back);    

}

int WindowsTerminal::Initialize() {

    // GetConsoleScreenBufferInfo(m_console_handle, &screen);
    // FillConsoleOutputCharacterA(
    //     m_console_handle, ' ', screen.dwSize.X * screen.dwSize.Y, top_left, &written
    // );
    // FillConsoleOutputAttribute(
    //     m_console_handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
    //     screen.dwSize.X * screen.dwSize.Y, top_left, &written
    // );
    // SetConsoleCursorPosition(m_console_handle, top_left);

    SMALL_RECT window_region; 
    COORD buffer_coord; 
    // BOOL fSuccess; 

    const auto width = 120;
    const auto height = 10;
	m_buffer_size.X = width;
	m_buffer_size.Y = height;

	buffer_coord.X = 0;
	buffer_coord.Y = 0;

	window_region.Left = window_region.Top = 0;
	window_region.Right = width - 1;
	window_region.Bottom = height - 1;
    m_buffer_handle = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

    if (m_buffer_handle == INVALID_HANDLE_VALUE) {
        return -1;
    }
    SetConsoleScreenBufferSize(m_buffer_handle, m_buffer_size);
    SetConsoleWindowInfo(m_buffer_handle, true, &window_region);

    // -----------------------------------
    // SafeReleaseArray(m_buffer_front);
    // m_buffer_front = new CHAR_INFO[width * height];

    SafeReleaseArray(m_buffer_back);
    m_buffer_back = new CHAR_INFO[width * height];

    // -----------------------------------
    // COORD top_left  = { 0, 0 };
    // CONSOLE_SCREEN_BUFFER_INFO screen;
    // DWORD written;
    // GetConsoleScreenBufferInfo(m_buffer_handle_front, &screen);
    // FillConsoleOutputCharacterA(
    //     m_buffer_handle_front, ' ', screen.dwSize.X * screen.dwSize.Y, top_left, &written
    // );
    // FillConsoleOutputAttribute(
    //     m_buffer_handle_front, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
    //     screen.dwSize.X * screen.dwSize.Y, top_left, &written
    // );
    // SetConsoleCursorPosition(m_buffer_handle_front, top_left);

    return 0;
}

void WindowsTerminal::Clear() {

    for (int row = 0; row < m_buffer_size.Y; ++row) {
        for (int col = 0; col < m_buffer_size.X; ++col) {
            const auto char_idx = row * m_buffer_size.X + col;
            m_buffer_back[char_idx].Char.AsciiChar = ' ';
            m_buffer_back[char_idx].Attributes = 0;
        }
    }

}

void WindowsTerminal::WriteText(const std::string& text) {
    const auto char_count = text.size();
    for (int char_idx = 0; char_idx < char_count; ++char_idx) {
        m_buffer_back[char_idx].Char.AsciiChar = (text[char_idx]);
        m_buffer_back[char_idx].Attributes = 0x0002;
    }
}

void WindowsTerminal::WriteChar(int row, int col, char ch) {
    const auto char_idx = row * m_buffer_size.X + col;
    m_buffer_back[char_idx].Char.AsciiChar = ch;
    m_buffer_back[char_idx].Attributes = 0x0002;
}

void WindowsTerminal::Present() {

    COORD coord; // buffer 里的坐标
    coord.X = 0;
    coord.Y = 0;

    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = m_buffer_size.X - 1;
    rect.Bottom = m_buffer_size.Y - 1;
    WriteConsoleOutput(m_buffer_handle, m_buffer_back, m_buffer_size, coord, &rect);

    SetConsoleActiveScreenBuffer(m_buffer_handle);

    //std::swap(m_buffer_front, m_buffer_back);
}

}