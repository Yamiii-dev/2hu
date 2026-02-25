//
// Created by belle on 25. 2. 2026.
//

#include "Bullet.h"

#include <complex>

#include "../math/Vector2.h"

void Bullet::Update(float deltaTime) {
    const float rad = rotation * M_PI / 180.0f;
    const Vector2 movement = {std::sin(rad), -std::cos(rad)};
    x += movement.x * speed * deltaTime;
    y += movement.y * speed * deltaTime;
    if (SDL_GetTicks() - spawnTime > 2000) {
        Destroy();
        return;
    }
}
