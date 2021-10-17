#include "Scene.h"
#include "Camera.h"
#include <vector>

namespace scene {

Scene::Scene(const std::string& name) 
    : m_root("SceneRoot")
    , m_name(name)
{
    m_all_nodes[m_root.m_name] = &m_root;

    // m_camera
}

Scene::~Scene() {
    for (auto& kv : m_all_nodes) {
        auto* node = kv.second;
        if (node == &m_root) continue;
        delete node;
    }
}

void Scene::Tick(float delta_time) {
    // todo: node release

    UpdateNodesTransform();
}

SceneNode* Scene::CreateSceneNode(const std::string& name) {
    if (m_all_nodes.find(name) == m_all_nodes.end()) {
        auto* new_node = new SceneNode(name);
        m_all_nodes[name] = new_node;
        return new_node;
    }
    return nullptr;
}

// bool Scene::RemoveSceneNode(SceneNode* node) {

// }

SceneNode* Scene::FindSceneNode(const std::string& name) {
    if (m_all_nodes.find(name) == m_all_nodes.end()) {
        return nullptr;
    }
    return m_all_nodes[name];
}

void Scene::UpdateNodesTransform() {
    std::vector<SceneNode*> nodes; 
    nodes.reserve(m_all_nodes.size() + 2);
    nodes.push_back(& m_root);

    for (int node_index = 0; node_index < nodes.size(); ++ node_index) {
        auto* node = nodes[node_index];
        if (node_index > 0) {
            node->m_world_transform.m_matrix = 
                node->m_parent->m_world_transform.m_matrix * node->m_transform.m_matrix;
        }
        for (auto* child : node->m_children) {
            nodes.push_back(child);
        }
    }
}

}