#include "Game/GameObjects/BallObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"
#include "Game/GameObjects/ScoreObject.hpp"
#include "Game/World.hpp"

#include <iostream>

World::World(SDL_Window& window, SDL_Renderer& renderer) :
window(window),
renderer(renderer) {
    
    int windowWidth { 0 };
    int windowHeight { 0 };
    SDL_GetWindowSize(&window, &windowWidth, &windowHeight);
    
    // Setup the Paddles
    gameObjects.push_front(new PaddleObject(20, (windowHeight / 2) - (PaddleObject::HEIGHT/2), SDLK_a, SDLK_z));
    gameObjects.push_front(new PaddleObject(windowWidth - 20 - PaddleObject::WIDTH, (windowHeight / 2) - (PaddleObject::HEIGHT/2), SDLK_j, SDLK_m));
    
    // Setup the Ball
    gameObjects.push_front(new BallObject((windowWidth/2) - (BallObject::WIDTH/2), (windowHeight/2) - (BallObject::HEIGHT/2)));
    
    // Setup the Scores
    gameObjects.push_front(new ScoreObject((windowWidth/2) - 50, 30, renderer));
    gameObjects.push_front(new ScoreObject((windowWidth/2) + 30, 30, renderer));
}

World::~World() {
    
    for(GameObject* gameObject : gameObjects) {
        delete gameObject;
    }
    
    delete movementSystem;
    delete renderSystem;
}

void World::run() {
    
    // Initial clearing of the screen before proceeding
    SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(&renderer);
    SDL_RenderPresent(&renderer);
    
    while(true) {
        
        updateFrameInformation();
        
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {

            if(event.key.keysym.sym == SDLK_F12) {
                std::cout << "FPS: " << framesPerSecond << std::endl;
            }
            
            if(event.type == SDL_QUIT) {
                isGameRunning = false;
                break;
            }
            
            switch(event.type) {
                case SDL_KEYUP:
                case SDL_KEYDOWN: {
                    for(GameObject* gameObject : gameObjects) {
                        InputComponent* inputComponent = gameObject->getComponent<InputComponent>();
                        if(inputComponent != nullptr) {
                            inputComponent->handleEvent(event);
                        }
                    }
                }
            }
        }
        
        if(!isGameRunning) {
            break;
        }
        
        for(GameObject* gameObject : gameObjects) {
            movementSystem->process(*gameObject, gameObjects);
        }
        
        // TODO: Finish with a lambda expression that will go through and find the specified type
        //std::find_if(gameObjects.begin(), gameObjects.end(), )
        // send to the system manager
        
        SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(&renderer);
        for(GameObject* gameObject : gameObjects) {
            renderSystem->update(gameObject);
        }
        renderPlayingField();
        SDL_RenderPresent(&renderer);
    }
}

void World::renderPlayingField() const {
    int windowWidth { 0 };
    int windowHeight { 0 };
    SDL_GetWindowSize(&window, &windowWidth, &windowHeight);
    
    SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    for (int height = 0; height < windowHeight; ++height)
    {
        if(height % 3 == 0)
        {
            SDL_RenderDrawPoint(&renderer, windowWidth / 2, height);
        }
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
