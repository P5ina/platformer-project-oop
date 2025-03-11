//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "input.h"

#include <string>

#include "raymath.h"

namespace Core {
    InputModule::InputModule(flecs::world &ecs) {
        ecs.module<InputModule>();

        ecs.set<Inputs>({
            .cameraMovement = Vector2Zero()
        });

        ecs.system<Inputs>("Read Inputs")
            .term_at(0).singleton()
            .kind(flecs::OnLoad)
            .each([](Inputs& inputs) {
                inputs.cameraMovement = Vector2Zero();
                if (IsKeyDown(KEY_W)) {
                    inputs.cameraMovement.y -= 1.0f;
                }
                if (IsKeyDown(KEY_S)) {
                    inputs.cameraMovement.y += 1.0f;
                }
                if (IsKeyDown(KEY_A)) {
                    inputs.cameraMovement.x -= 1.0f;
                }
                if (IsKeyDown(KEY_D)) {
                    inputs.cameraMovement.x += 1.0f;
                }
                inputs.cameraMovement = Vector2Normalize(inputs.cameraMovement);

                // TraceLog(LOG_INFO, ("Camera movements: " + std::to_string(inputs.cameraMovement.x) + ", " + std::to_string(inputs.cameraMovement.y)).c_str());
            });
    }

}
