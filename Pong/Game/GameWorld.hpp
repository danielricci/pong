#pragma once

#include "Game/GameObjects/GameObject.hpp"
#include "Game/GameObjects/GameOverObject.hpp"

#include "Game/Systems/MovementSystem.hpp"
#include "Game/Systems/RenderSystem.hpp"
#include "Game/Systems/ScoringSystem.hpp"

#include <SDL.h>

#include <list>

class GameWorld {
public:
    GameWorld(SDL_Window& window, SDL_Renderer& renderer);
    ~GameWorld();
    void run();
    
private:
    SDL_Window& window;
    int windowWidth { 0 };
    int windowHeight { 0 };
    
    SDL_Renderer& renderer;
    
    std::list<GameObject*> gameObjects;
    GameOverObject* gameOverObject { nullptr };
    
    MovementSystem* movementSystem { new MovementSystem(window) };
    RenderSystem* renderSystem { new RenderSystem(renderer) };
    ScoringSystem* scoringSystem { new ScoringSystem(window) };
    
    int framesPerSecond { 0 };
    bool isGameQuit { false };
    bool isWindowFocused { false };
    bool stopRendering { false };
    
    void clean();
    void destroy();
    void initialize();
    void renderPlayingField() const;
    void resetGame();
    void updateFrameInformation();
    
    template<typename T> T* getGameObject() {
        for(GameObject* gameObject : gameObjects) {
            T* object = dynamic_cast<T*>(gameObject);
            if(object != nullptr) {
                return object;
            }
        }
        return nullptr;
    }
    
    template<typename T> std::list<T*> getGameObjects() {
        std::list<T*> objects;
        for(GameObject* gameObject : gameObjects) {
            T* object = dynamic_cast<T*>(gameObject);
            if(object != nullptr) {
                objects.push_back(object);
            }
        }
        return objects;
    }
};
