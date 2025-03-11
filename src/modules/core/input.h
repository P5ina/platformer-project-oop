//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef INPUT_H
#define INPUT_H
#include "raylib.h"
#include "flecs.h"

namespace Core {
    struct Inputs {
        Vector2 cameraMovement;
    };

    struct InputModule {
        explicit InputModule(flecs::world& ecs);
    };
}

#endif //INPUT_H
