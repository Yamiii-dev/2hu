//
// Created by belle on 22. 2. 2026.
//

#include "Scene.h"

#include <algorithm>
#include <iostream>

void Scene::Initialize(std::unique_ptr<GameObject> game_object) {
    auto ptr = game_object.get();
    spawn_queue.push_back(std::move(game_object));
    ptr->Init(this);
}

void Scene::Update(float deltaTime) {
    int i = 0;
    for (auto& game_object : game_objects) {
        if (!game_object->enabled) continue;
        game_object->Update(deltaTime);
        i++;
    }
    game_objects.erase(
        std::ranges::remove_if(game_objects,
                               [](const std::unique_ptr<GameObject>& obj) {
                                   return obj->to_destroy;
                               }).begin(),
            game_objects.end());
    for (auto& obj : spawn_queue) {
        game_objects.push_back(std::move(obj));
    }
    spawn_queue.clear();
}

void Scene::Draw(SDL_Renderer *renderer) const {
    std::vector<GameObject*> sorted;
    sorted.reserve(game_objects.size());
    for (const auto& obj : game_objects) {
        sorted.push_back(obj.get());
    }
    std::ranges::stable_sort(sorted,
                             [](const GameObject* a, const GameObject* b) {
                                 return a->drawPriority < b->drawPriority;
                             });
    for (auto& game_object : sorted) {
        if (!game_object->enabled) continue;
        game_object->Draw(renderer);
    }
}
