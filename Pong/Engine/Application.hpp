#pragma once

#include <SDL.h>

class Application {
public:
    Application(const char* title, int width, int height) {
    }
    
    virtual ~Application() = default;
    virtual void run() {
    }
    
protected:
    SDL_Window* window { nullptr };
    SDL_Renderer* windowRenderer { nullptr };
};
