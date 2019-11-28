#include "Game.hpp"

#include <iostream>

Game::Game(const char* title, int width, int height) {
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
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == nullptr) {
                std::cerr << "SDL renderer could not be created: " << SDL_GetError() << std::endl;
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
                std::cout << "Initialization Successful" << std::endl;
                world = new World(*window, *renderer);
            }
        }
    }
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    delete world;
}

void Game::run() {
    world->run();
}
