#include "Game/GameObjects/BallObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"
#include "Game/GameObjects/ScoreObject.hpp"
#include "Game/GameWorld.hpp"

#include <iostream>

GameWorld::GameWorld(SDL_Window& window, SDL_Renderer& renderer) :
window(window),
renderer(renderer) {
    
    // Get the world dimensions
    int windowWidth { 0 };
    int windowHeight { 0 };
    SDL_GetWindowSize(&window, &windowWidth, &windowHeight);
    
    // Setup the Paddles
    PaddleObject* paddle1 = new PaddleObject(20, (windowHeight / 2) - (PaddleObject::HEIGHT/2), SDLK_a, SDLK_z);
    gameObjects.push_front(paddle1);
    PaddleObject* paddle2 = new PaddleObject(windowWidth - 20 - PaddleObject::WIDTH, (windowHeight / 2) - (PaddleObject::HEIGHT/2), SDLK_j, SDLK_m);
    gameObjects.push_front(paddle2);
    
    // Setup the Ball
    gameObjects.push_front(new BallObject((windowWidth/2) - (BallObject::WIDTH/2), (windowHeight/2) - (BallObject::HEIGHT/2)));
    
    // Setup the Score
    ScoreObject* scoreObject1 = new ScoreObject((windowWidth/2) - 50, 30, renderer);
    scoreObject1->setPaddleObject(*paddle1);
    gameObjects.push_front(scoreObject1);
    ScoreObject* scoreObject2 = new ScoreObject((windowWidth/2) + 30, 30, renderer);
    scoreObject2->setPaddleObject(*paddle2);
    gameObjects.push_front(scoreObject2);
}

GameWorld::~GameWorld() {
    
    for(GameObject* gameObject : gameObjects) {
        delete gameObject;
    }
    
    delete movementSystem;
    delete renderSystem;
    delete scoringSystem;
}

void GameWorld::run() {
    
    // Initial clearing of the screen before proceeding
    SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(&renderer);
    SDL_RenderPresent(&renderer);
    
    while(true) {
        
        updateFrameInformation();
        
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                isGameRunning = false;
                break;
            }
            else if(event.type == SDL_WINDOWEVENT) {
                switch(event.window.event) {
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        isGamefocused = false;
                        break;
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        isGamefocused = true;
                        break;
                }
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
        
        // Verify if the game should quit based on previous user input
        if(!isGameRunning) {
            break;
        }
        
        // If the game has lost focus then do not update the movement of the game
        if(!isGamefocused) {
            for(GameObject* gameObject : gameObjects) {
                movementSystem->process(*gameObject, gameObjects);
            }
            scoringSystem->process(this->getGameObject<BallObject>(), this->getGameObjects<ScoreObject>());
        }
        
        // Set up for rendering
        SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(&renderer);
        
        // Render System
        for(GameObject* gameObject : gameObjects) {
            renderSystem->update(gameObject);
        }
        
        // Render the playing field
        renderPlayingField();
        
        // Blit everything
        SDL_RenderPresent(&renderer);
    }
}

void GameWorld::renderPlayingField() const {
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

void GameWorld::updateFrameInformation() {

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
