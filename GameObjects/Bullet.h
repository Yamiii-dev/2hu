//
// Created by belle on 25. 2. 2026.
//

#ifndef INC_2HU_BULLET_H
#define INC_2HU_BULLET_H


#include <SDL3/SDL_timer.h>

#include "Sprite.h"


class Bullet : public Sprite {
public:
    Bullet(const char* filename, SDL_Renderer *render)
        : Sprite(filename, render) {
        radius = size.x * scale;
    }
    void Init(Scene *_parent) override {
        Sprite::Init(_parent);

        spawnTime = SDL_GetTicks();
    };
    void Update(float deltaTime) override;
    int radius = 26;
protected:
    Uint64 spawnTime = 0;
    float speed = 1024;
};


#endif //INC_2HU_BULLET_H