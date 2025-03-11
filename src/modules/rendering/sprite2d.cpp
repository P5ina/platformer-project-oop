//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "sprite2d.h"

#include "rendering.h"

namespace Rendering {
    SpriteRenderingModule::SpriteRenderingModule(flecs::world &ecs) {
        ecs.module<SpriteRenderingModule>();

        ecs.system<Sprite2DComponent, Core::TransformComponent>()
            .kind<OnLayerForegroundDraw>()
            .each(Render);
    }

    void SpriteRenderingModule::Render(Sprite2DComponent &sprite, Core::TransformComponent &transform) {
        auto rect = sprite.dest;
        rect.x = transform.position.x;
        rect.y = transform.position.y;
        auto origin = Vector2 { sprite.dest.height / 2, sprite.dest.width / 2 };
        DrawRectanglePro(rect, origin, transform.rotation, PURPLE);
    }

}
