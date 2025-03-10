//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef CORE_H
#define CORE_H

#include "flecs.h"

namespace Core {
    struct CoreModule {
        explicit CoreModule(flecs::world& ecs);
    };
}

#endif //CORE_H
