#include "Game/World.hpp"

#include <iostream>

World::World(SDL_Window& window, SDL_Renderer& renderer) :
window(window),
renderer(renderer) {
    
    // Get the dimensions of the world
    int width { 0 };
    int height { 0 };
    SDL_GetWindowSize(&window, &width, &height);
    
    // Setup the Paddles
    gameObjects.push_front(new PaddleObject(40, (height / 2) - 20, SDLK_a, SDLK_z));
    gameObjects.push_front(new PaddleObject(width - 40, (height / 2) - 20, SDLK_j, SDLK_m));
}

void World::update() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        if(event.key.keysym.sym == SDLK_F12) {
            std::cout << "FPS: " << framesPerSecond << std::endl;
        }
        
        switch(event.type) {
            case SDL_QUIT: {
                isGameRunning = false;
                break;
            }
            default:
                //for(GameObject* gameObject : gameObjects) {
                    //movementSystem->process(gameObject);
    //            }
                break;
        }
    }
}

void World::render() {
    // Clear screen
    SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(&renderer);

    // Draw the back buffer
    SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);

    // Blit
    SDL_RenderPresent(&renderer);
}

void World::run() {
    isGameRunning = true;
    while(isGameRunning) {
        updateFrameInformation();
        update();
        render();
    }
}

void World::updateFrameInformation() {

    // Initialization of data
    static int totalFrames = 0;
    static double totalTime = 0.f;
    static long long int startTime = SDL_GetPerformanceCounter();

    // Calculate elapsed time
    long long int endTime = SDL_GetPerformanceCounter();
    long long int elapsedTime = endTime - startTime;
    startTime = endTime;

    // Calculate frame time (eg: 16.667ms)
    double totalTimeMilliseconds = ((elapsedTime * 1000)/static_cast<double>(SDL_GetPerformanceFrequency()));

    // Increment time result and frames counter
    totalTime += totalTimeMilliseconds;
    ++totalFrames;

    if(totalTime >= 1000) {
        // Reset the time and frames for the next batch
        framesPerSecond = totalFrames;
        totalTime = 0;
        totalFrames = 0;
    }
}
