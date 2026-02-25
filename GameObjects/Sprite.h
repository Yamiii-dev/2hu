//
// Created by belle on 22. 2. 2026.
//

#ifndef INC_2HU_SPRITE_H
#define INC_2HU_SPRITE_H
#include <SDL3/SDL_render.h>

#include "../classes/GameObject.h"
#include "../math/Vector2.h"


class Sprite : public GameObject {
public:
    Sprite(const char *filePath, SDL_Renderer *render);
    ~Sprite();

    void Update(float deltaTime) override;
    void Draw(SDL_Renderer *renderer) override;
    float x = 0, y = 0;
    float scale = 1;
    float rotation = 0;
    Vector2 size{};
private:
    SDL_Texture *tex;
};


#endif //INC_2HU_SPRITE_H