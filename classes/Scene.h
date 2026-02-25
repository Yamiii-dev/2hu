//
// Created by belle on 22. 2. 2026.
//

#ifndef INC_2HU_SCENE_H
#define INC_2HU_SCENE_H
#include <memory>
#include <vector>
#include <SDL3/SDL_render.h>

#include "GameObject.h"


class Scene {
public:
    std::vector<std::unique_ptr<GameObject>> game_objects = std::vector<std::unique_ptr<GameObject>>();
    void Initialize(std::unique_ptr<GameObject> game_object);
    void Update(float deltaTime);
    void Draw(SDL_Renderer *renderer) const;
    template<typename T>
    std::vector<T*> GetObjects() const;
    template<typename T>
    std::vector<T*> GetObjects(std::string tag);
    Scene() = default;
    SDL_Renderer *render;
private:
    std::vector<std::unique_ptr<GameObject>> spawn_queue;
};

template<typename T>
std::vector<T *> Scene::GetObjects() const {

    static_assert(std::is_base_of<GameObject, T>::value,
                  "T must inherit from GameObject");

    std::vector<T*> output;
    for (auto& obj : game_objects) {
        if (T* casted = dynamic_cast<T*>(obj.get()))
            output.push_back(casted);
    }
    return output;
}

template<typename T>
std::vector<T *> Scene::GetObjects(std::string tag) {

    static_assert(std::is_base_of<GameObject, T>::value,
                  "T must inherit from GameObject");

    std::vector<T*> output;
    for (auto& obj : game_objects) {
        if (T* casted = dynamic_cast<T*>(obj.get()) && obj->tag == tag)
            output.push_back(casted);
    }
    return output;
}


#endif //INC_2HU_SCENE_H