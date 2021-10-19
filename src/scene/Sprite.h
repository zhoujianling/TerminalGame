#pragma once
#include "Component.h"

namespace scene {

// decoupled from sprite
class SpritePattern {

};

// class SpritePatternFactory {

// };

class Sprite : public ComponentBase {

public:
    ~Sprite() override {}

    ComponentType GetType() override  { return ComponentType::Sprite; }

private:
    SpritePattern m_pattern;

};

}