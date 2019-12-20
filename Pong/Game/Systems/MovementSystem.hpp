#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include <SDL.h>

#include <list>

class MovementSystem {
public:
    MovementSystem(SDL_Window& window);
    void process(GameObject& currentGameObject, const std::list<GameObject*>& gameObjects) const;
private:
    int worldWidth;
    int worldHeight;
};
