//
// Created by belle on 22. 2. 2026.
//

#include "Player.h"

#include "PlayerBullet.h"
#include "../CONFIG.h"
#include "../classes/Scene.h"
#include "../math/Vector2.h"

void Player::Init(Scene *_parent) {
    Sprite::Init(_parent);
    auto focus_ptr = std::make_unique<Sprite>("assets/sprites/focus.png", _parent->render);
    focus = focus_ptr.get();
    parent->Initialize(std::move(focus_ptr));
    focus->scale = scale;
    focus->enabled = false;
    focus->drawPriority = 3;
    radius = focus->size.x * scale;
    drawPriority = 2;
}

void Player::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    const bool* key_state = SDL_GetKeyboardState(0);
    Vector2 movement = Vector2();
    if (key_state[SDL_SCANCODE_W]) movement.y = -1;
    if (key_state[SDL_SCANCODE_S]) movement.y = 1;
    if (key_state[SDL_SCANCODE_D]) movement.x = 1;
    if (key_state[SDL_SCANCODE_A]) movement.x = -1;

    float usedSpeed = speed;
    focus->enabled = false;
    if (key_state[SDL_SCANCODE_LSHIFT]) {
        focus->enabled = true;
        usedSpeed = focusSpeed;
    }

    Vector2 finalMove = {x + (movement.x * usedSpeed * deltaTime), y + (movement.y * usedSpeed * deltaTime)};
    if (finalMove.x >= 0 && finalMove.x <= PLAY_AREA_X - (size.x * scale)) {
        x = finalMove.x;
    }
    if (finalMove.y >= 0 && finalMove.y <= PLAY_AREA_Y - (size.y * scale)) {
        y = finalMove.y;
    }
    focus->x = x;
    focus->y = y;
    if (bulletCooldown > 0) bulletCooldown -= deltaTime;
    if (key_state[SDL_SCANCODE_SPACE] && bulletCooldown <= 0) {
        auto bullet = std::make_unique<PlayerBullet>(parent->render);
        float w = size.x * scale;
        float h = size.y * scale;
        bullet->x = x + w / 3;
        bullet->y = y;
        bullet->scale = scale;
        parent->Initialize(std::move(bullet));
        bulletCooldown = 1 / bulletsPerSecond;
    }
}