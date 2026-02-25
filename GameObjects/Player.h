//
// Created by belle on 22. 2. 2026.
//

#ifndef INC_2HU_PLAYER_H
#define INC_2HU_PLAYER_H
#include "Sprite.h"


class Player : public Sprite {
public:
    void Init(Scene *_parent) override;

    void Update(float deltaTime) override;
    Player(const char * filePath, SDL_Renderer * render) : Sprite(filePath, render){};
    int radius = 26;
private:
    float speed = 256;
    float focusSpeed = 128;
    Sprite* focus;
    float bulletCooldown = 0;
    float bulletsPerSecond = 15;
};


#endif //INC_2HU_PLAYER_H