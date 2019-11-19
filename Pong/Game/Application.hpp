#pragma once

#include <SDL.h>

class Application {
public:
    Application(const char* title, int width, int height);
    virtual ~Application();
    virtual void run() = 0;
    
protected:
    SDL_Window* window { nullptr };
    SDL_Renderer* windowRenderer { nullptr };
};
