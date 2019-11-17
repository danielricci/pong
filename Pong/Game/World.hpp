#pragma once

#include "GameObject.hpp"

#include <SDL.h>

#include <list>

class World final {
public:
    World(SDL_Window& window, SDL_Renderer& renderer);
    ~World() = default;
    void run();
private:

    std::list<GameObject*> gameObjects;
    
    SDL_Window& window;
    SDL_Renderer& renderer;
    
    int framesPerSecond { 0 };
    bool isGameRunning { false };
    void updateFrameInformation();
    
    void input();
    void update();
    void render();
};
