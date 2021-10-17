#pragma once
#include "Node.h"

namespace scene {

class Camera {

public:
    Camera();

private:
    SceneNode* m_attached_node = nullptr;
};

class CameraNode : public SceneNode {

private:
    Camera m_camera; // owns it
};
    
}