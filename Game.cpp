//
// Created by belle on 22. 2. 2026.
//


#include "Game.h"
#include "CONFIG.h"
#include "GLOBAL.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "classes/FontObject.h"
#include "GameObjects/Player.h"
#include "GameObjects/Enemies/WaveFairy.h"

Game::Game(const char* title) {
    SDL_Init( SDL_INIT_VIDEO );
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow(title, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    render = SDL_CreateRenderer(window, nullptr);
    currentScene.render = render;
    if (render == nullptr) {
        std::cout << "Failed to initialize: " << SDL_GetError() << std::endl;
        return;
    }
}

void Game::Run() {
    auto player = std::make_unique<Player>("assets/sprites/reimu.png", render);
    player->scale = 2;
    player->x = PLAY_AREA_X / 2 - (player->size.x);
    player->y = PLAY_AREA_Y - (player->size.y * 2);
    currentScene.Initialize(std::move(player));

    auto fairy = std::make_unique<WaveFairy>(render);
    fairy->scale = 2;
    fairy->y = 32;
    currentScene.Initialize(std::move(fairy));

    SDL_Rect playArea = {PADDING, PADDING, PLAY_AREA_X, PLAY_AREA_Y};
    SDL_Rect uiArea = {PLAY_AREA_X + PADDING, 0, UI_AREA_X, 480};

    int frameDelay = 1000.0f / FRAMERATE;

    SDL_Event ev;

    FontObject cirnoFont = FontObject("assets/fonts/Cirno.ttf");

    while (running) {
        Uint32 frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_EVENT_QUIT || ev.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
                std::cout << "Quitting..." << std::endl;
                running = false;
                break;
            }
        }
        SDL_SetRenderDrawColor(render, 18, 18, 22, 255);
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_SetRenderViewport(render, &playArea);
        Update();
        SDL_SetRenderViewport(render, &uiArea);
        int y = PADDING;
        y += cirnoFont.DrawText(render, PADDING, y, ("Score: " + std::to_string(score)).c_str());
        y += PADDING;

        SDL_SetRenderViewport(render, nullptr);

        SDL_RenderPresent(render);

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_Quit();
}

void Game::Update() {
    current_update = SDL_GetTicks();
    const float deltaTime = static_cast<float>(current_update - last_update) / 1000.0f;
    last_update = current_update;
    SDL_RenderFillRect(render, nullptr);
    currentScene.Update(deltaTime);
    currentScene.Draw(render);
    float framerate = 1 / deltaTime;
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    SDL_RenderDebugText(render, 0, 0, ("FPS: " + std::to_string(framerate)).c_str());
}

Game::~Game() {
    SDL_DestroyRenderer(render);
    SDL_Quit();
}