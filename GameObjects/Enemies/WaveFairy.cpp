//
// Created by belle on 24. 2. 2026.
//

#include "WaveFairy.h"

#include <complex>

void WaveFairy::Init(Scene *_parent) {
    Enemy::Init(_parent);
    start = {x, y};
    scoreGain = 100;
}

void WaveFairy::Update(float deltaTime) {
    Enemy::Update(deltaTime);
    timeAlive += deltaTime;
    Vector2 movement = {x + (96 * deltaTime), start.y + ((size.y * std::sin(3 * timeAlive) * scale))};
    x = movement.x;
    y = movement.y;
}
