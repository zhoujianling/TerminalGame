#pragma once

#include "../core/ITickable.h"

namespace game {

class Entity : public core::ITickable {

public:
    ~Entity() override {}

private:
    int m_id;
};

}