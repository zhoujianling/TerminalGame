#pragma once
#include "Node.h"

namespace scene {

class Sprite {

public:

private:
    SceneNode* m_node = nullptr;

};

class SpriteNode : public SceneNode {

public:

private:
    Sprite m_sprite;

};

}