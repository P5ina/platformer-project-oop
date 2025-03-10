//
// Created by Timur Turatbekov on 10.03.2025.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "raylib.h"

namespace Core {
    /** Transform component used for game objects.
     *  For UI please refer to UITransformComponent
     */
    struct TransformComponent {
        Vector2 position;
        /// Rotation in radians
        float rotation;
    };
}

#endif //TRANSFORM_H
