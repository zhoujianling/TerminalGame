#pragma once

namespace scene
{

class SceneNode;

enum class ComponentType {
    Camera = 0,
    Sprite,

};

class ComponentBase {
    friend class SceneNode;

public:
    virtual ~ComponentBase() {}

    virtual ComponentType GetType() = 0;

    SceneNode* GetNode() { return m_node; }

private:
    SceneNode* m_node = nullptr;

};

} // namespace scene
