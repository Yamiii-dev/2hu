//
// Created by belle on 22. 2. 2026.
//

#include "Sprite.h"

#include <iostream>
#include <SDL3_image/SDL_image.h>

Sprite::Sprite(const char *filePath, SDL_Renderer *render) : GameObject() {
    tex = IMG_LoadTexture(render, filePath);
    if (!tex) {
        std::cout << "Error loading Sprite " << filePath << ": " << SDL_GetError() << std::endl;
    }
    else {
        SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_PIXELART);
        float w = tex->w;
        float h = tex->h;
        size = {w, h};
    }
}

Sprite::~Sprite() {
    SDL_DestroyTexture(tex);
}

void Sprite::Update(float deltaTime) {
    GameObject::Update(deltaTime);
}

void Sprite::Draw(SDL_Renderer *renderer) {
    GameObject::Draw(renderer);
    if (tex == NULL) return;
    const float w = size.x;
    const float h = size.y;
    SDL_FRect dRect = {x, y, w * scale, h * scale};
    SDL_FPoint center = {(w * scale) / 2, (h * scale) / 2};
    SDL_RenderTextureRotated(renderer, tex, nullptr, &dRect, rotation, &center, SDL_FLIP_NONE);
}