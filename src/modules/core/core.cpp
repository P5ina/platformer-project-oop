//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "core.h"

#include "transform.h"

namespace Core {
    CoreModule::CoreModule(flecs::world &ecs) {
        ecs.module<CoreModule>();

        ecs.component<TransformComponent>();
    }
}

