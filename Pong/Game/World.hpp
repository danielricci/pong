#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"

#include "Game/Systems/MovementSystem.hpp"

#include <SDL.h>

#include <list>

class World {
public:
    World(SDL_Window& window, SDL_Renderer& renderer);
    ~World() = default;
    void run();
private:
    
    std::list<GameObject*> gameObjects;
    MovementSystem* movementSystem = new MovementSystem();
    
    SDL_Window& window;
    SDL_Renderer& renderer;
    
    int framesPerSecond { 0 };
    bool isGameRunning { false };
    void updateFrameInformation();
    
    void update();
    void render();
};
