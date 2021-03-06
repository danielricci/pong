/**
* MIT License
*
* Copyright (c) 2020 Daniel Ricci {@literal <thedanny09@icloud.com>}
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "Game/Components/PaddleInputComponent.hpp"
#include "Game/GameObjects/BallObject.hpp"
#include "Game/GameObjects/PaddleObject.hpp"
#include "Game/GameObjects/ScoreObject.hpp"
#include "Game/GameWorld.hpp"
#include "Game/Managers/InputManager.hpp"
#include "Game/Managers/SoundManager.hpp"

#include <SDL.h>

#include <iostream>

GameWorld::GameWorld(SDL_Window& window, SDL_Renderer& renderer) :
window(window),
renderer(renderer) {
    initialize();
    
    movementSystem = new MovementSystem(window);
    renderSystem = new RenderSystem(renderer);
    scoringSystem = new ScoringSystem(window);
}

void GameWorld::initialize() {
    
    // Initialize the manager classes
    InputManager::getInstance();
    SoundManager::getInstance();
    
    // Get the window width and height and store it for use
    SDL_GetWindowSize(&window, &windowWidth, &windowHeight);
        
    // Setup the Paddles
    PaddleObject* paddle1 = new PaddleObject(20, (windowHeight / 2) - (PaddleObject::HEIGHT/2));
    PaddleObject* paddle2 = new PaddleObject(windowWidth - 20 - PaddleObject::WIDTH, (windowHeight / 2) - (PaddleObject::HEIGHT/2));
    paddle1->addComponent(new PaddleInputComponent(SDLK_a, SDLK_z, SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_LEFTY));
    paddle2->addComponent(new PaddleInputComponent(SDLK_j, SDLK_m, SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_RIGHTY));
    gameObjects.push_front(paddle1);
    gameObjects.push_front(paddle2);
    
    // Setup the Ball
    gameObjects.push_front(new BallObject((windowWidth/2) - (BallObject::WIDTH/2), (windowHeight/2) - (BallObject::HEIGHT/2)));
    
    // Setup the Score
    ScoreObject* scoreObject1 = new ScoreObject((windowWidth/2) - 50, 30, renderer);
    ScoreObject* scoreObject2 = new ScoreObject((windowWidth/2) + 30, 30, renderer);
    scoreObject1->setPaddleObject(*paddle1);
    scoreObject2->setPaddleObject(*paddle2);
    gameObjects.push_front(scoreObject1);
    gameObjects.push_front(scoreObject2);
    
    // Setup the game over object
    gameObjects.push_front(new GameOverObject(windowWidth, windowHeight, renderer));
        
    // By default the game runs in AI mode for player 2
    paddle2->getComponent<PaddleInputComponent>()->enabled = false;
}

GameWorld::~GameWorld() {
    destroy();
}

void GameWorld::clean() {
    for(GameObject* gameObject : gameObjects) {
        delete gameObject;
        gameObject = nullptr;
    }
    gameObjects.clear();
}

void GameWorld::destroy() {
    clean();
    
    SoundManager::getInstance()->terminate();
    InputManager::getInstance()->terminate();
    
    if(movementSystem != nullptr) {
        delete movementSystem;
        movementSystem = nullptr;
    }
    
    if(renderSystem != nullptr) {
        delete renderSystem;
        renderSystem = nullptr;
    }
    
    if(scoringSystem != nullptr) {
        delete scoringSystem;
        scoringSystem = nullptr;
    }
}

void GameWorld::run() {
    // Initial clearing of the screen before proceeding
    SDL_SetRenderDrawColor(&renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(&renderer);
    SDL_RenderPresent(&renderer);
    
    bool stopRendering { false };
    
    while(true) {
        
        updateFrameInformation();
        
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
                        
            if(event.type == SDL_WINDOWEVENT) {
                switch(event.window.event) {
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        isWindowFocused = true;
                        break;
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        isWindowFocused = false;
                        break;
                }
            }

            if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
                isGameQuit = true;
                break;
            }
            
            if(getGameObject<GameOverObject>()->getIsGameOver() && event.key.keysym.sym == SDLK_RETURN) {
                clean();
                initialize();
                stopRendering = false;
                break;
            }
            
            if(event.key.keysym.sym == SDLK_1 && event.type == SDL_KEYUP) {
                SoundManager::getInstance()->toggleSound();
            }
            else if(event.key.keysym.sym == SDLK_2 && event.type == SDL_KEYUP) {
                std::list<PaddleInputComponent*> inputs = getGameComponents<PaddleObject, PaddleInputComponent>();
                if(inputs.size() == 2) {
                    inputs.front()->enabled = !inputs.front()->enabled;
                };
            };
            
            // Handle any inputs
            InputManager::getInstance()->process(event, getGameComponents<PaddleObject, InputComponent>());
        }
        
        if(isGameQuit) {
            break;
        }
        
        if(!isWindowFocused) {
            continue;
        }
        
        if(!getGameObject<GameOverObject>()->getIsGameOver()) {
            // Move the game objects
            movementSystem->process(gameObjects);
        
            // Scoring System
            scoringSystem->process(*this->getGameObject<BallObject>(), this->getGameObjects<ScoreObject>(), *getGameObject<GameOverObject>());
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
            if(getGameObject<GameOverObject>()->getIsGameOver()) {
                stopRendering = true;
            }
        }
    }
}

void GameWorld::renderPlayingField() const {
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
