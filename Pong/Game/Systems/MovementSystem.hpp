#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include <SDL.h>

#include <list>

class MovementSystem {
public:
    MovementSystem(SDL_Window& window);
    void process(GameObject& currentGameObject, const std::list<GameObject*>& gameObjects);
private:
    int worldWidth;
    int worldHeight;
    
    const int maxVelocityIncreases { 3 };
    const int paddleSectors { 5 };
    int numBallCollisions { 0 };
};
