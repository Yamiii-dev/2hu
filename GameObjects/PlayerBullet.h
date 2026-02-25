//
// Created by belle on 22. 2. 2026.
//

#ifndef INC_2HU_PLAYERBULLET_H
#define INC_2HU_PLAYERBULLET_H
#include <SDL3/SDL_timer.h>

#include "Bullet.h"


class PlayerBullet : public Bullet {
public:
    PlayerBullet(SDL_Renderer *render)
        : Bullet("assets/sprites/player_bullet.png", render) {
        tag = "PlayerBullet";
    }
    void Update(float deltaTime) override;
private:
    Uint64 spawnTime = 0;
};


#endif //INC_2HU_PLAYERBULLET_H