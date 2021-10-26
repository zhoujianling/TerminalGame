#pragma once
#include "Component.h"
#include <string>

namespace scene {


class Sprite : public ComponentBase {

public:
    ~Sprite() override {}

    ComponentType GetType() const override  { return ComponentType::Sprite; }

private:
    std::string m_appearance_id;

};

}