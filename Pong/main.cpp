#include <SDL.h>
#include <stdio.h>

struct Rectangle {
    const int WIDTH { 1024 };
    const int HEIGHT { 768 };
} ScreenDimensions;

int main(int argc, char** argv) {
    
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: SDL could not initialize: %s\n", SDL_GetError());
    }
    else {
        window = SDL_CreateWindow("Pong",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  ScreenDimensions.WIDTH,
                                  ScreenDimensions.HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if(window == nullptr) {
            printf("Window could not be created: %s\n", SDL_GetError());
        }
        else
        {
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            
            // Initialize and run the game loop
            SDL_Event event;
            bool quit { false };
            while(!quit) {
                while(SDL_PollEvent(&event)) {
                    if(event.type == SDL_QUIT) {
                        quit = true;
                    }
                    else if (event.type == SDL_KEYDOWN) {
                    }
                    else if(event.type == SDL_MOUSEBUTTONDOWN) {
                    }
                }
            }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}
