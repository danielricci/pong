#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"


#include <SDL.h>

#include <list>

class World {
public:
    World(SDL_Window& window, SDL_Renderer& renderer);
    ~World() = default;
    void run();
private:

    PaddleObject* po = new PaddleObject(0, 0);
    std::list<GameObject*> gameObjects;
    
    SDL_Window& window;
    SDL_Renderer& renderer;
    
    int framesPerSecond { 0 };
    bool isGameRunning { false };
    void updateFrameInformation();
    
    void update();
    void render();
};
