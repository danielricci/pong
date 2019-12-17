#include "Game/Systems/RenderSystem.hpp"
#include "Game/Components/RenderComponent.hpp"

#include <SDL.h>

RenderSystem::RenderSystem(SDL_Renderer& renderer) : renderer(renderer) {
}

void RenderSystem::update(GameObject* gameObject) {
    if(gameObject != nullptr) {
        RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
        if(renderComponent != nullptr) {
            SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
            SDL_Rect rectangle = gameObject->getTransform()->rectangle();
            SDL_RenderFillRect(&renderer, &rectangle);
        }
    }
}
