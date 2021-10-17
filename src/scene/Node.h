#pragma once

#include "Transform.h"
#include <set>
#include <string>

namespace scene {

class SceneNode {
    friend class Scene;

public:
    Transform& GetTransform() { return m_transform; }

    const Transform& GetWorldTransform() { return m_world_transform; }

    void Attach(SceneNode* node);

    void Detach(SceneNode* node);

private:
    SceneNode(const std::string& name);

private:
    Transform m_transform; // owns it

    Transform m_world_transform; // updated by scene

    std::set<SceneNode*> m_children;

    SceneNode* m_parent = nullptr;    

    std::string m_name;

};

}