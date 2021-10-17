#include "Input.h"

#include <conio.h>

namespace core {

void KeyboardInput::CollectInput() {

    if (_kbhit()) {
        const auto ch = _getch();
        // std::cout << "ch is " << ch << std::endl;
    }

}

}