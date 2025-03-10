//
// Created by Timur Turatbekov on 03.03.2025.
//

#include <raylib.h>
#include <flecs.h>
#include <modules/rendering.h>

int main() {
    TraceLog(LOG_INFO, "Starting the game.");

    constexpr int WIDTH = 1280;
    constexpr int HEIGHT = 800;
    InitWindow(WIDTH, HEIGHT, "Miner");
    SetTargetFPS(60);

    flecs::world ecs;

    ecs.import<Rendering::RenderingModule>();

    while (ecs.progress()) { }

    CloseWindow();
    TraceLog(LOG_INFO, "Stopping game...");
    return 0;
}
