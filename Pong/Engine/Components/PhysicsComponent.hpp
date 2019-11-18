#pragma once

#include <SDL.h>

#include "Engine/GameObject.hpp"

template <class T>
class PhysicsComponent {
public:
    PhysicsComponent(T& gameObject) : gameObject(gameObject) { }
    virtual ~PhysicsComponent() = default;
    virtual void update(const SDL_Event& event) = 0;
protected:
    T& getGameObject() const { return gameObject; }
private:
    T& gameObject;
};
