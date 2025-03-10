//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "camera.h"

namespace Rendering {
    CameraModule::CameraModule(flecs::world &ecs) {
        ecs.module<CameraModule>();

        ecs.component<Camera2DComponent>();
    }
}
