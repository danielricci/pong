#pragma once

#include "Game/GameObjects/GameObject.hpp"

#include "Game/Systems/MovementSystem.hpp"
#include "Game/Systems/RenderSystem.hpp"

#include <SDL.h>

#include <list>

class World {
public:
    World(SDL_Window& window, SDL_Renderer& renderer);
    ~World();
    void run();
private:

    SDL_Window& window;
    SDL_Renderer& renderer;
    
    std::list<GameObject*> gameObjects;

    MovementSystem* movementSystem = new MovementSystem();
    RenderSystem* renderSystem = new RenderSystem(renderer);
    
    int framesPerSecond { 0 };
    bool isGameRunning { true };
    void updateFrameInformation();
    void renderPlayingField() const;
};
