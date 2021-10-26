#include "Game.h"
#include "../scene/Scene.h"

namespace core {

    Game::Game() {

    }

    Game::~Game() {
        // for (auto* scene : m_scenes) {
        //     // delete scene;
        // }
    }

    void Game::Tick(float delta_time) {
        for (auto& scene : m_scenes) {
            scene->Tick(delta_time);
        }
    }

    scene::Scene* Game::CreateScene(const std::string& scene_name, bool is_active ) {
        auto* scene = new scene::Scene(scene_name);
        if (is_active) {
            m_active_scene = scene;
        }
        // m_scenes.push_back(scene);
        m_scenes.emplace_back();
        m_scenes.back().reset(scene);
        return scene;
    }

}
