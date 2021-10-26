#pragma once
#include "Component.h"

namespace scene {

    class HeroController : public ComponentBase {

        bool CanTick() const override;

        void Tick(float delta_time) override;

        ComponentType GetType() const override { return ComponentType::HeroController; }

    };

}