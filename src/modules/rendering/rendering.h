//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef RENDERING_H
#define RENDERING_H

#include <flecs.h>

namespace Rendering {

    constexpr int WINDOW_WIDTH = 1280;
    constexpr int WINDOW_HEIGHT = 800;

    struct OnPreDraw { };
    struct OnPreDrawWorld { };
    struct OnLayerBackgroundDraw { };
    struct OnLayerForegroundDraw { };
    struct OnPostDrawWorld { };
    struct OnLayerUIDraw { };
    struct OnPostDraw { };

    struct RenderingModule {
        explicit RenderingModule(flecs::world& ecs);
    };
}

#endif //RENDERING_H
