//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "flecs.h"
#include "raylib.h"

namespace Rendering {
    struct Camera2DComponent {
        Camera2D camera;
        float moveSpeed;
        float zoomSpeed;
        float minZoom;
        float maxZoom;
    };

    struct CameraModule {
        explicit CameraModule(flecs::world& ecs);

        void Movement(Camera2DComponent& camera);
    };
};

#endif //CAMERA_H
