#pragma once 
#include <vector>
#include "../scene/Transform.h"

namespace core {

    class Appearance;

    struct CharPosition {

        int m_row;

        int m_col;

        int m_stack;

        CharPosition(int row, int col);
    };

    struct Shape {

        std::vector<CharPosition> m_char_positions;

    };

    struct ScreenElement {

        Shape m_shape;

        scene::Transform m_transform; 

        Appearance* m_appearance = nullptr;
        
    };

}
