//
// Created by belle on 24. 2. 2026.
//

#ifndef INC_2HU_WAVEFAIRY_H
#define INC_2HU_WAVEFAIRY_H
#include "../Enemy.h"


class WaveFairy : public Enemy {
public:
    WaveFairy(SDL_Renderer *render) : Enemy("assets/sprites/fairy.png", render) {

    }
    void Init(Scene *_parent) override;
    void Update(float deltaTime) override;
private:
    float timeAlive = 0;
    Vector2 start;
};


#endif //INC_2HU_WAVEFAIRY_H