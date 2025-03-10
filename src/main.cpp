//
// Created by Timur Turatbekov on 03.03.2025.
//

#include <raylib.h>
#include <flecs.h>
#include <modules/core/core.h>
#include <modules/core/transform.h>
#include <modules/rendering/rendering.h>
#include <modules/rendering/sprite2d.h>

int main() {
    TraceLog(LOG_INFO, "Starting game.");

    InitWindow(Rendering::WINDOW_WIDTH, Rendering::WINDOW_HEIGHT, "Miner");
    SetTargetFPS(60);

    flecs::world ecs;

    ecs.import<Core::CoreModule>();
    ecs.import<Rendering::RenderingModule>();

    auto box = ecs.entity("Test rect")
        .set<Core::TransformComponent>({
            .position = { 0.0f, 0.0f },
            .rotation = 0.0f,
        })
        .set<Rendering::Sprite2DComponent>({
            .textureId = "test",
            .dest = Rectangle {
                .height = 100.0f,
                .width = 100.0f,
            }
        });

    while (ecs.progress()) { }

    CloseWindow();
    TraceLog(LOG_INFO, "Stopping game.");
    return 0;
}
