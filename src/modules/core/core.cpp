//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "core.h"

#include "input.h"
#include "transform.h"

namespace Core {
    CoreModule::CoreModule(flecs::world &ecs) {
        ecs.module<CoreModule>();

        ecs.import<InputModule>();

        ecs.component<TransformComponent>();
    }
}

