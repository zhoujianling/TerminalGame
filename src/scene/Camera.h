#pragma once
#include "Component.h"

namespace scene {

class Camera : public ComponentBase {

public:
    Camera();

    ~Camera() override {}

    ComponentType GetType() const override  { return ComponentType::Camera; }

private:

};

}