//
// Created by belle on 25. 2. 2026.
//

#include "FontObject.h"

FontObject::FontObject(const char *filePath) {
    font = TTF_OpenFont(filePath, 24);
    if (!font) {
        std::cout << "Error loading Font " << filePath << ": " << SDL_GetError() << std::endl;
    }
}

FontObject::~FontObject() {
    TTF_CloseFont(font);
}

int FontObject::DrawText(SDL_Renderer *render, const int x, const int y, const char *text, const SDL_Color color) {
    if (lastText == text && lastTexture != nullptr) {
        SDL_Texture *textTexture = lastTexture;
        const SDL_FRect textRect = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(textTexture->w), static_cast<float>(textTexture->h)};
        SDL_RenderTexture(render, textTexture, nullptr, &textRect);
        const int height = textTexture->h;
        return height;
    }
    else {
        SDL_DestroyTexture(lastTexture);
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, 0, color);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(render, textSurface);
        SDL_DestroySurface(textSurface);
        const SDL_FRect textRect = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(textTexture->w), static_cast<float>(textTexture->h)};
        SDL_RenderTexture(render, textTexture, nullptr, &textRect);
        const int height = textTexture->h;
        lastTexture = textTexture;
        lastText = text;
        return height;
    }
}
