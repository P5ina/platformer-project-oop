//
// Created by Timur Turatbekov on 10.03.2025.
//

#include "rendering.h"

#include "raylib.h"
#include <array>

namespace Rendering {
    RenderingModule::RenderingModule(flecs::world &ecs) {
        ecs.module<RenderingModule>();

        std::array RenderPhases = {
            ecs.entity<OnPreDraw>(),
            ecs.entity<OnLayerBackgroundDraw>(),
            ecs.entity<OnLayer1Draw>(),
            ecs.entity<OnLayerUIDraw>(),
            ecs.entity<OnPostDraw>()
        };

        flecs::entity_t PriorPhase = flecs::OnStore;

        for(auto& Phase : RenderPhases)
        {
            Phase.add(flecs::Phase).depends_on(PriorPhase);
            PriorPhase = Phase;
        }

        ecs.system("Check Exit Request")
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
    }
};

