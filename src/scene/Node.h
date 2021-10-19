#pragma once

#include "Transform.h"
#include <set>
#include <string>
#include <vector>
#include <memory>

namespace scene {
    class ComponentBase;

class SceneNode {
    friend class Scene;

public:

    ~SceneNode();

    Transform& GetTransform() { return m_transform; }

    const Transform& GetWorldTransform() { return m_world_transform; }

    void Attach(SceneNode* node);

    void Detach(SceneNode* node);

    void AddComponent(ComponentBase* comp);

private:
    SceneNode(const std::string& name);

private:
    Transform m_transform; // owns it

    Transform m_world_transform; // updated by scene

    std::set<SceneNode*> m_children;

    std::vector<std::unique_ptr<ComponentBase> > m_components;

    SceneNode* m_parent = nullptr;    

    Scene* m_scene = nullptr;    

    std::string m_name;

};

}