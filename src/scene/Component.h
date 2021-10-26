#pragma once

namespace scene
{

class SceneNode;

enum class ComponentType {
    Camera = 0,
    Sprite,
    HeroController
};

class ComponentBase {
    friend class SceneNode;

public:
    virtual ~ComponentBase() {}

    virtual ComponentType GetType() const = 0;

    virtual bool CanTick() const;

    virtual void Tick(float delta_time);

    SceneNode* GetNode() const { return m_node; }

private:
    SceneNode* m_node = nullptr;

};

} // namespace scene
