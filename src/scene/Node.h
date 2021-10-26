#pragma once

#include "Transform.h"
#include <set>
#include <string>
#include <vector>
#include <memory>

namespace scene {
    class ComponentBase;


    struct ComponentIterator {

    public:
        ComponentIterator(std::vector<std::unique_ptr<ComponentBase> >::iterator iter)
        : m_iter(iter) {}

        ComponentBase* operator*() { return m_iter->get(); }
        void operator++() { ++m_iter; }
        bool operator!=(const ComponentIterator& rhs) { return m_iter != rhs.m_iter; }
    
    private:
        std::vector<std::unique_ptr<ComponentBase> >::iterator m_iter;
    };


    class SceneNode {
        friend class Scene;

    public:

        ~SceneNode();

        Transform& GetTransform() { return m_transform; }

        const Transform& GetWorldTransform() { return m_world_transform; }

        void Attach(SceneNode* node);

        void Detach(SceneNode* node);

        void Tick(float delta_time);

        void AddComponent(ComponentBase* comp);

        Scene* GetScene() const { return m_scene; }

        ComponentIterator begin() { return ComponentIterator(m_components.begin()); }
        ComponentIterator end() { return ComponentIterator(m_components.end()); }

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