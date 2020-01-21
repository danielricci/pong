#pragma once

#include "Game/GameObjects/BallObject.hpp"
#include "Game/GameObjects/GameObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"

#include <SDL.h>

#include <list>

class MovementSystem {
public:
    MovementSystem(SDL_Window& window);
    void process(const std::list<GameObject*>& gameObjects);
private:
    void processBallMovement(BallObject* ballObject) const;
    void processPaddleMovement(PaddleObject* paddleObject) const;
    
    int worldWidth;
    int worldHeight;
    
    std::list<GameObject*> gameObjects;
    
    const int PADDLE_SECTIONS { 5 };
};
