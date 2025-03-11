//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "camera.h"

#include <modules/core/input.h>

#include "raymath.h"

namespace Rendering {
    CameraModule::CameraModule(flecs::world &ecs) {
        ecs.module<CameraModule>();

        ecs.component<Camera2DComponent>();

        ecs.system<Camera2DComponent, const Core::Inputs>("Camera Movement")
            .term_at(1).singleton()
            .kind(flecs::OnUpdate)
            .each([](flecs::iter& it, size_t, Camera2DComponent& camera, const Core::Inputs& inputs) {
                auto to_move = Vector2Scale(inputs.cameraMovement, camera.moveSpeed);
                camera.camera.target += to_move * it.delta_time();
            });
    }


}
