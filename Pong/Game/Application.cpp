#include "Application.hpp"

#include <SDL.h>

#include <iostream>

Application::Application(const char* title, int width, int height) {
    std::cout << "Application Initializing"<< std::endl;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialize all sub-systems: " << SDL_GetError() << std::endl;
    }
    else {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if(window == nullptr) {
            std::cerr << "SDL window could not be created: " << SDL_GetError() << std::endl;
        }
        else {
            windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(windowRenderer == nullptr) {
                std::cerr << "SDL renderer could not be created: " << SDL_GetError() << std::endl;
            }
            else {
                SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
                std::cout << "Initialization Successful" << std::endl;
            }
        }
    }
}

Application::~Application() {
    SDL_DestroyRenderer(windowRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
