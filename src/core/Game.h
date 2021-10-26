#pragma once

#include <vector>
#include <string>
#include <memory>
#include "../core/ITickable.h"

namespace core {
    class GameCore;

}

namespace scene {
    class Scene;
} // namespace scene


namespace core {

class Game : public core::ITickable {
    friend class core::GameCore;
public:
    Game();

    ~Game() override;

    void Tick(float delta_time);

    scene::Scene* CreateScene(const std::string& scene_name, bool is_active = true);

    scene::Scene* GetActiveAcene() {
        return m_active_scene;
    }

private:
    // game has scene
    std::vector<std::unique_ptr<scene::Scene> > m_scenes;

    scene::Scene* m_active_scene = nullptr;

    core::GameCore* m_core = nullptr;
};

}
