#include "Application.hpp"
#include <iostream>

Application::Application(const char* title, int width, int height) : title(title), width(width), height(height) {
}

Application::~Application() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::initalize() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not be initialize all sub-systems: " << SDL_GetError() << std::endl;
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
            }
        }
    }
}

void Application::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch(event.type) {
        case SDL_QUIT:
            running = false;
            break;
    }
}

void Application::update() {
}

void Application::render() {
}
  
    
    
    
    
    /*
     #include <stdio.h>

     const int SCREEN_WIDTH { 1024 };
     const int SCREEN_HEIGHT { 768 };

     SDL_Window* window { nullptr };
    SDL_Surface* surface { nullptr };
    SDL_Renderer* renderer { nullptr };
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: SDL could not initialize: %s\n", SDL_GetError());
    }
    else {
        window = SDL_CreateWindow("Pong",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if(window == nullptr) {
            printf("Window could not be created: %s\n", SDL_GetError());
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == nullptr) {
                printf("Renderer could not be created: %s\n", SDL_GetError());
            }
            else {
                // Initialize and run the game loop
                SDL_Event event;
                bool quit { false };
                
                // Game loop
                while(!quit) {
                    
                    // Input
                    while(SDL_PollEvent(&event)) {
                        if(event.type == SDL_QUIT) {
                            quit = true;
                        }
                        else if (event.type == SDL_KEYDOWN) {
                        }
                        else if(event.type == SDL_MOUSEBUTTONDOWN) {
                        }
                    }
                                     
                    //Clear screen
                    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);

                    // Draw Shape
                    SDL_Rect rectangle {
                       .x = SCREEN_WIDTH/4,
                       .y = SCREEN_HEIGHT/4,
                       .w = SCREEN_WIDTH/2,
                       .h = SCREEN_HEIGHT/2
                    };
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
                    SDL_RenderFillRect(renderer, &rectangle);
                    
                    // Update
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
    
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    
    SDL_FreeSurface(surface);
    surface = nullptr;
    
    SDL_DestroyWindow(window);
    window = nullptr;
    
    SDL_Quit();
     */
