#include "Game.hpp"
#include <iostream>

Game::Game(const char* title, int width, int height) : width(width), height(height) {
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
                running = true;
                std::cout << "Initialization Successful" << std::endl;
            }
        }
    }
    std::cout << "Running = " << running << std::endl;
}

Game::~Game() {
    delete player;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run() {
    while(running) {
        input();
        update();
        render();
    }
}

void Game::input() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        switch(event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                player->input(event);
                break;
        }
    }
}

void Game::update() {
    player->update(0.f);
}

void Game::render() {
    //Clear screen
    //SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    //SDL_RenderClear(renderer);
    
    // Render the shape
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
    //SDL_RenderFillRect(renderer, player->getRectangle());
    //SDL_RenderPresent(renderer);
}
