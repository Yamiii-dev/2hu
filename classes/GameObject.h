//
// Created by belle on 22. 2. 2026.
//

#ifndef INC_2HU_GAMEOBJECT_H
#define INC_2HU_GAMEOBJECT_H
#include <memory>
#include <SDL3/SDL_render.h>
class Scene;


class GameObject {
public:
    virtual void Init(Scene *_parent) {
        this->parent = _parent;
        enabled = true;
    }
    virtual void Update(float deltaTime){};
    virtual void Draw(SDL_Renderer *renderer){};
    GameObject() = default;
    virtual ~GameObject() = default;
    Scene *parent{};
    int drawPriority = 0;
    bool enabled = false;
    void Destroy();
    bool to_destroy = false;
    std::string tag{};
};


#endif //INC_2HU_GAMEOBJECT_H