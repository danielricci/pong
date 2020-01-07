#include "GameWindow.hpp"

#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>

GameWindow::GameWindow(const char* title, int width, int height) {
    std::cout << "Application Initializing"<< std::endl;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    }
    else {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if(window == nullptr) {
            std::cerr << "SDL window could not be created: " << SDL_GetError() << std::endl;
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == nullptr) {
                std::cerr << "SDL renderer could not be created: " << SDL_GetError() << std::endl;
            }
            else {
                if(TTF_Init() < 0) {
                    std::cerr << "SDL_ttf could not be initialized: " << TTF_GetError() << std::endl;
                }
                else {
                    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                        std::cerr << "SDL_mixer could not be initilized: " << Mix_GetError() << std::endl;
                    }
                    else {
                        world = new GameWorld(*window, *renderer);
                        ready = true;
                        std::cout << "Initialization Successful" << std::endl;
                    }
                }
            }
        }
    }
}

GameWindow::~GameWindow() {
    if(world != nullptr) {
        delete world;
        world = nullptr;
    }

    Mix_Quit();
    TTF_Quit();
    
    if(renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    
    if(window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    
    SDL_Quit();
}

void GameWindow::show() const {
    if(ready && world != nullptr) {
        world->run();
    }
}
