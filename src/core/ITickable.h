#pragma once 

namespace core {

class ITickable {

public:
    virtual ~ITickable() {}

    virtual void Tick(float delta_time) = 0;

};

}