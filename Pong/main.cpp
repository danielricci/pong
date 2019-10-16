#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH { 1024 };
const int SCREEN_HEIGHT { 768 };

int main(int argc, char** argv) {
    
    SDL_Window* window { nullptr };
    SDL_Surface* surface { nullptr };
    SDL_Renderer* renderer { nullptr };
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
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
}
