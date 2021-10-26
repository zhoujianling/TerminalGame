#include "Input.h"

#include <conio.h>

namespace core {

void KeyboardInput::CollectInput() {
    m_pressed_keys.clear();
    while (_kbhit()) {
        const auto ch = _getch();
        if (ch >= 'a' && ch <= 'z') {
            const auto k = static_cast<Key>((int)ch);
            m_pressed_keys.insert(k);
        } else if (ch == '\033') {
            _getch();
            const auto next_ch = _getch();
            switch (next_ch) {
                case 'A':
                    m_pressed_keys.insert(Key::Up);
                break;
                case 'B':
                    m_pressed_keys.insert(Key::Down);
                break;
                case 'C':
                    m_pressed_keys.insert(Key::Right);
                break;
                case 'D':
                    m_pressed_keys.insert(Key::Left);
                break;
            }
        }
        // std::cout << "ch is " << ch << std::endl;
    }

}

bool KeyboardInput::IsKeyDown(Key ch) const {
    return m_pressed_keys.find(ch) != m_pressed_keys.end();
}

}