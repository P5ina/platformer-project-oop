//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "rendering.h"

#include "raylib.h"
#include "camera.h"
#include <array>
#include <modules/core/core.h>

#include "sprite2d.h"

namespace Rendering {
    RenderingModule::RenderingModule(flecs::world &ecs) {
        ecs.module<RenderingModule>();

        std::array RenderPhases = {
            ecs.entity<OnPreDraw>(),
            ecs.entity<OnPreDrawWorld>(),
            ecs.entity<OnLayerBackgroundDraw>(),
            ecs.entity<OnLayerForegroundDraw>(),
            ecs.entity<OnPostDrawWorld>(),
            ecs.entity<OnLayerUIDraw>(),
            ecs.entity<OnPostDraw>()
        };

        flecs::entity_t PriorPhase = flecs::OnStore;

        for(auto& Phase : RenderPhases)
        {
            Phase.add(flecs::Phase).depends_on(PriorPhase);
            PriorPhase = Phase;
        }

        ecs.import<Core::CoreModule>();
        ecs.import<CameraModule>();
        ecs.import<SpriteRenderingModule>();

        auto cameraEntity = ecs.entity("MainCamera")
            .set<Rendering::Camera2DComponent>({
                {
                    { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f },
                    { 0.0f, 0.0f },
                    0.0f,
                    1.0f
                },
                200.0f,
                0.1f,
                0.1f,
                5.0f
            });

        ecs.system("CheckExitRequest")
            .kind(flecs::PostFrame)
            .run([](flecs::iter& it) {
                if(WindowShouldClose()) {
                    it.world().quit();
                }
            });

        ecs.system("RaylibBeginDraw")
            .kind<OnPreDraw>()
            .run([](flecs::iter& it) {
                BeginDrawing();
                ClearBackground(BLACK);
            });

        ecs.system("RaylibEndDraw")
            .kind<OnPostDraw>()
            .run([](flecs::iter& it) {
                EndDrawing();
            });

        ecs.system("RaylibBeginDraw2D")
            .kind<OnPreDrawWorld>()
            .run([](flecs::iter& it) {
                Camera2D* camera = nullptr;
                it.world().each<Camera2DComponent>([&camera](Camera2DComponent& c) {
                    camera = &c.camera;
                });

                if (!camera) {
                    TraceLog(LOG_ERROR, "No camera found!");
                    return;
                }

                BeginMode2D(*camera);
            });

        ecs.system("RaylibEndDraw2D")
            .kind<OnPostDrawWorld>()
            .run([](flecs::iter& it) {
                EndMode2D();
            });
    }
};

