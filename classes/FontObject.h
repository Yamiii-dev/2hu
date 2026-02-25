//
// Created by belle on 25. 2. 2026.
//

#ifndef INC_2HU_TEXTOBJECT_H
#define INC_2HU_TEXTOBJECT_H

#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>


class FontObject {
public:
    FontObject(const char* filePath);
    ~FontObject();
    int DrawText(SDL_Renderer *render, int x, int y, const char* text, SDL_Color color = {255, 255, 255, 255});
private:
    TTF_Font *font;
    SDL_Texture *lastTexture{};
    std::string lastText{};
};


#endif //INC_2HU_TEXTOBJECT_H