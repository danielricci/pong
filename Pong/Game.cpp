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
            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer == nullptr) {
                std::cerr << "SDL renderer could not be created: " << SDL_GetError() << std::endl;
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
                std::cout << "Initialization Successful" << std::endl;
                isGameRunning = true;
            }
        }
    }
    
    if(isGameRunning) {
        std::cout << "Game is running" << std::endl;
    }
    else {
        std::cerr << "Game failed to run properly" << std::endl;
    }
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::startGame() {
    while(isGameRunning) {
        processGameInput();
        processGameUpdate();
        ProcessGameRender();
    }
}

void Game::processGameInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        switch(event.type) {
            case SDL_QUIT:
                isGameRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::processGameUpdate() {
}

void Game::ProcessGameRender() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    // Draw the back buffer
    SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderPresent(renderer);
}
