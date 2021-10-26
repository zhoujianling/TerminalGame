#include "HeroController.h"
#include "Node.h"
#include "../core/GameCore.h"
#include "../core/Input.h"

#include <iostream>

namespace scene
{
    bool HeroController::CanTick() const { return true; }

    void HeroController::Tick(float delta_time) {
            //std::cout << "val is " << (int)ch << std::endl;

        auto* input = core::GameCore::GetInstance()->GetInput();
        auto& transform = GetNode()->GetTransform();
        if (input->IsKeyDown(core::Key::A)) {
            transform.Translate({ -1.0f, 0.0f });
            // auto t = transform.m_matrix * Vector3(0, 0, 1.0f);
            // std::cout << "x: " << t.m_x << "y: " << t.m_y << "z: " << t.m_z << std::endl;
            // exit(-1);
        }
        if (input->IsKeyDown(core::Key::D)) {
            transform.Translate({ +1.0f, 0.0f });
        }
        if (input->IsKeyDown(core::Key::W)) {
            transform.Translate({ 0.0f, -1.0f });
        }
        if (input->IsKeyDown(core::Key::S)) {
            transform.Translate({ 0.0f, +0.9f });
        }
    }

} // namespace scene
