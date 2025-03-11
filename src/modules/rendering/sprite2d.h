//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef SPRITE2D_H
#define SPRITE2D_H

#include "flecs.h"
#include "raylib.h"
#include <string>
#include <modules/core/transform.h>

namespace Rendering {
    struct Sprite2DComponent {
        std::string textureId;
        Rectangle dest;
        // Color tint;
    };

    struct SpriteRenderingModule {
        explicit SpriteRenderingModule(flecs::world& ecs);

        static void Render(Sprite2DComponent& sprite, Core::TransformComponent& transform);
    };
}

#endif //SPRITE2D_H
