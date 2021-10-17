#include "Node.h"
#include "assert.h"

namespace scene {

SceneNode::SceneNode(const std::string& name) 
    : m_name(name)
{
}

void SceneNode::Attach(SceneNode* node) {
    assert(node);
    assert(node != this);
    if (node->m_parent) {
        node->m_parent->Detach(node);
    }
    m_children.insert(node); 
    node->m_parent = this;
}

void SceneNode::Detach(SceneNode* node) {
    assert(node);
    if (m_children.find(node) == m_children.end()) return;
    m_children.erase(node);
    node->m_parent = nullptr;

}

}