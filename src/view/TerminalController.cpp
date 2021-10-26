#include "TerminalController.h"

#include "../core/GameCore.h"
#include "../core/Game.h"
#include "../scene/Scene.h"
#include "../scene/Camera.h"
#include "../scene/Sprite.h"

#include <cstdlib>
#include <iostream>

namespace core {


TerminalController::TerminalController() {
    m_terminal.Initialize();

    m_init_time = std::chrono::system_clock::now().time_since_epoch();
}

TerminalController::~TerminalController() {
}

void TerminalController::Tick(float delta_time) {
    Draw();

    m_terminal.Present();
}

void TerminalController::Draw() {
    {
        m_elements.clear();
        auto* game = m_core->GetGame();
        if (game) {
            DrawGame(game);
        }
    }

    m_terminal.Clear();
    {
        const auto curr_time = std::chrono::system_clock::now().time_since_epoch();

        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>((curr_time - m_init_time)).count();
        auto text = std::string("curr time is ") + std::to_string(millis / 1000.0f); 

        m_terminal.WriteText(text);

        FillScreen();
    }
}

void TerminalController::DrawGame(core::Game* game) {

    auto* active_scene = game->GetActiveAcene();
    if (active_scene) {
        DrawScene(*active_scene);
    }
}

void TerminalController::DrawScene(scene::Scene& scene) {

    // collect 
    for (auto* scene_node : scene) {
        for (auto* comp : *scene_node) {
            if (comp->GetType() == scene::ComponentType::Sprite) {
                auto* sprite_comp = dynamic_cast<scene::Sprite*>(comp);
                DrawSprite(sprite_comp);
            } 
            // scene_node->  
        }
    }
}

void TerminalController::DrawSprite(scene::Sprite* sprite) {

    m_elements.emplace_back(); 
    m_elements.back().m_transform = sprite->GetNode()->GetWorldTransform();
    m_elements.back().m_shape.m_char_positions.emplace_back(0, 0);
}

void TerminalController::FillScreen() {

    for (auto& element : m_elements) {
        auto& world_transform = element.m_transform;
        for (auto& char_pos : element.m_shape.m_char_positions) {
            // int row = char_pos
            const Vector3 model_space_pos(char_pos.m_col, char_pos.m_row, 1.0f);
            const auto world_space_pos = world_transform.m_matrix * model_space_pos;
            const auto row = (int)world_space_pos.m_y;
            const auto col = (int)world_space_pos.m_x;
            m_terminal.WriteChar(row, col, '#');
        }
    }

}

}