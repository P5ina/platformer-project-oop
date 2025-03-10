//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef RENDERING_H
#define RENDERING_H
#include <flecs.h>

namespace Rendering {
    struct OnPreDraw { };
    struct OnLayerBackgroundDraw { };
    struct OnLayer1Draw { };
    struct OnLayerUIDraw { };
    struct OnPostDraw { };

    struct RenderingModule {
        explicit RenderingModule(flecs::world& ecs);
    };
}

#endif //RENDERING_H
