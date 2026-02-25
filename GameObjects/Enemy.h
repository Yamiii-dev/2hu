//
// Created by belle on 24. 2. 2026.
//

#ifndef INC_2HU_ENEMY_H
#define INC_2HU_ENEMY_H
#include "Sprite.h"


class Enemy : public Sprite {
public:
    int health = 10;
    int radius = 26;
    void Update(float deltaTime) override;
    void Init(Scene *_parent) override;
    Enemy(const char* filename, SDL_Renderer* render) : Sprite(filename, render) {
        tag = "Enemy";
    };
protected:
    int scoreGain = 0;
};


#endif //INC_2HU_ENEMY_H