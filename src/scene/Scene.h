#pragma once

#include "Node.h"
#include "../core/ITickable.h"
#include <map>
#include <vector>

namespace scene {

    class Camera;

    class Sprite;

class Scene : public core::ITickable {
    friend class Game;
public:
    Scene(const std::string& name);
    ~Scene() override;

    void Tick(float delta_time) override;

    scene::Sprite* CreateSprite();

    SceneNode* CreateSceneNode(const std::string& name); 

    // bool RemoveSceneNode(SceneNode* node);

    SceneNode* FindSceneNode(const std::string& name);

    Camera* GetActiveCamera() { return m_active_camera; }

    void SetActiveCamera(Camera* camera);

private:

    void UpdateNodesTransform();

private:
    SceneNode m_root;

    std::string m_name;

    std::map<std::string, SceneNode*> m_all_nodes;

    // std::vector<Camera*> m_all_cameras;

    Camera* m_active_camera = nullptr;

};

}