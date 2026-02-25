//
// Created by belle on 24. 2. 2026.
//

#include "Enemy.h"
#include "../GLOBAL.h"

#include <complex>

#include "PlayerBullet.h"
#include "../classes/Scene.h"

void Enemy::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    std::vector<PlayerBullet*> bullets = parent->GetObjects<PlayerBullet>();
    for (const auto bullet : bullets) {
        const Vector2 distanceV = {bullet->x - x, bullet->y - y};
        const int distance = std::sqrt(pow(distanceV.x, 2) + pow(distanceV.y, 2));
        if (distance < radius + bullet->radius) {
            bullet->Destroy();
            health--;
        }
    }
    if (health <= 0) {
        score += scoreGain;
        Destroy();
    }
}

void Enemy::Init(Scene *_parent) {
    Sprite::Init(_parent);
    radius = size.x * scale;
}
