//
// Created by belle on 22. 2. 2026.
//

#ifndef INC_2HU_GAME_H
#define INC_2HU_GAME_H
#include <string>

#include "classes/Scene.h"


class Game {
public:
    Game(const char* title);
    ~Game();
    bool running = true;

    void Run();

private:
    Scene currentScene = Scene();
    SDL_Renderer *render;
    Uint64 last_update = 0;
    Uint64 current_update = 0;
    void Update();
};


#endif //INC_2HU_GAME_H