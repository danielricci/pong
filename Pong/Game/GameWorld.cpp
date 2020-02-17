#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/GameObjects/BallObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"
#include "Game/GameObjects/ScoreObject.hpp"
#include "Game/GameWorld.hpp"

#include <SDL.h>

#include <iostream>

GameWorld::GameWorld(SDL_Window& window, SDL_Renderer& renderer) :
window(window),
renderer(renderer) {
    // Get the world dimensions
    SDL_GetWindowSize(&window, &windowWidth, &windowHeight);
    initialize();
}

void GameWorld::initialize() {
    // Setup the Paddles
    PaddleObject* paddle1 = new PaddleObject(20, (windowHeight / 2) - (PaddleObject::HEIGHT/2));
    paddle1->addComponent(new PaddleInputComponent(SDLK_a, SDLK_z));
    gameObjects.push_front(paddle1);
    
    PaddleObject* paddle2 = new PaddleObject(windowWidth - 20 - PaddleObject::WIDTH, (windowHeight / 2) - (PaddleObject::HEIGHT/2));
    paddle2->addComponent(new PaddleInputComponent(SDLK_j, SDLK_m));
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
    
    // Game over object
    gameOverObject = new GameOverObject(windowWidth, windowHeight, renderer);
    gameObjects.push_front(gameOverObject);
}

void GameWorld::clean() {
    for(GameObject* gameObject : gameObjects) {
        delete gameObject;
        gameObject = nullptr;
    }
    gameObjects.clear();
    
    stopRendering = false;
}

void GameWorld::destroy() {
    clean();
    
    delete movementSystem;
    delete renderSystem;
    delete scoringSystem;
}

GameWorld::~GameWorld() {
    destroy();
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
            if(event.type == SDL_QUIT || ((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) && event.key.keysym.sym == SDLK_ESCAPE)) {
                isGameQuit = true;
                break;
            }
            else if(event.type == SDL_WINDOWEVENT) {
                switch(event.window.event) {
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        isWindowFocused = true;
                        break;
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        isWindowFocused = false;
                        break;
                }
            }

            switch(event.type) {
                case SDL_KEYUP:
                case SDL_KEYDOWN: {
                    if(gameOverObject->getIsGameOver()) {
                        if(event.key.keysym.sym == SDLK_RETURN) {
                            clean();
                            initialize();
                        }
                    }
                    else {
                        for(GameObject* gameObject : gameObjects) {
                            InputComponent* inputComponent = gameObject->getComponent<InputComponent>();
                            if(inputComponent != nullptr) {
                                inputComponent->handleEvent(event);
                            }
                        }
                    }
                }
            }
        }
        
        if(isGameQuit) {
            break;
        }
        
        if(!isWindowFocused) {
            continue;
        }
        
        if(!gameOverObject->getIsGameOver()) {
            // Move the game objects
            movementSystem->process(gameObjects);
        
            // Scoring System
            scoringSystem->process(*this->getGameObject<BallObject>(), this->getGameObjects<ScoreObject>(), *gameOverObject);
        }
        
        if(!stopRendering) {
            // Render System
            SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(&renderer);
            for(GameObject* gameObject : gameObjects) {
                renderSystem->update(gameObject);
            }
            
            // Render the field
            renderPlayingField();
            
            // Blit everything
            SDL_RenderPresent(&renderer);
            
            // Rendering will occur once, then it gets blocked
            if(gameOverObject->getIsGameOver()) {
                stopRendering = true;
            }
        }
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
    
    //std::cout << "Elapsed Time = " << elapsedTime << " | " << "Time = " << totalTime << " | Frames = " << totalFrames << " | FPS = " << framesPerSecond << " | Performance Counter = " << SDL_GetPerformanceCounter() << " | Performance Frequency = " << SDL_GetPerformanceFrequency() << std::endl;
}

void GameWorld::resetGame() {
    
}
