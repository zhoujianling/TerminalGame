#include "Component.h"

namespace scene
{
    bool ComponentBase::CanTick() const {
        return false;
    };

    void ComponentBase::Tick(float delta_time) {
        
    }

} // namespace scene
