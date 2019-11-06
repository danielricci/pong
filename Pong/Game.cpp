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
            windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            
            if(windowRenderer == nullptr) {
                std::cerr << "SDL renderer could not be created: " << SDL_GetError() << std::endl;
            }
            else {
                SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
                std::cout << "Initialization Successful" << std::endl;
                isGameRunning = true;

                // Perform last minute initializations of the game
                int width = 0;
                int height = 0;
                SDL_GetRendererOutputSize(windowRenderer, &width, &height);
                playerOne = new Paddle(40, (height/2) - 20);
                playerTwo = new Paddle(width - 40, (height/2) - 20);

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
    SDL_DestroyRenderer(windowRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void Game::updateFrameInformation() {
    
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

void Game::startMainGameLoop() {
    while(isGameRunning) {
        updateFrameInformation();
        input();
        update();
        render();
    }
}

void Game::input() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        switch(event.type) {
            case SDL_QUIT: {
                isGameRunning = false;
                break;
            }
            case SDL_KEYUP: {
                if(event.key.keysym.sym == SDLK_F12) {
                    std::cout << "FPS: " << framesPerSecond << std::endl;
                }
            }
            case SDL_KEYDOWN: {
                playerOne->input(event);
                break;
            }
        }
    }
}

void Game::update() {
    playerOne->update();
}

void Game::render() {
    // Clear screen
    SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(windowRenderer);
    
    // Draw the back buffer
    SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    playerOne->render(*windowRenderer);
    playerTwo->render(*windowRenderer);
    
    // Blit
    SDL_RenderPresent(windowRenderer);
}
