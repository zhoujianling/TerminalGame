#pragma once

#include "Node.h"
#include "../core/ITickable.h"
#include <map>
#include <vector>

namespace scene {

    class Camera;

    class Sprite;

// std::map<int, int>::iterator;

template<typename K, typename V>
struct MapValueIterator {
public:
    using MapIterator = typename std::map<K, V>::iterator;
    MapValueIterator(MapIterator iter)
    // : m_current_iter(m.begin())
    : m_iter(iter)
    {
    }

    V& operator*() { return m_iter->second; }
    void operator++() { ++m_iter; }
    bool operator==(const MapValueIterator& rhs) { return m_iter == rhs.m_iter;}
    bool operator!=(const MapValueIterator& rhs) { return m_iter != rhs.m_iter;}

private:
    MapIterator m_iter;
    // std::map<K, V>::iterator m_current_iter;
};
using SceneNodeIterator = MapValueIterator<std::string, SceneNode*>;

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

    SceneNode* GetRoot() { return & m_root; }

    Camera* GetActiveCamera() { return m_active_camera; }

    void SetActiveCamera(Camera* camera);

    SceneNodeIterator begin() { return SceneNodeIterator(m_all_nodes.begin()); }
    SceneNodeIterator end() { return SceneNodeIterator(m_all_nodes.end()); }

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