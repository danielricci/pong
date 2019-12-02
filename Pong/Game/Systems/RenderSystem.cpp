#include "Game/Systems/RenderSystem.hpp"
#include "Game/Components/RenderComponent.hpp"

#include <SDL.h>

RenderSystem::RenderSystem(SDL_Renderer& renderer) : renderer(renderer) {
}

void RenderSystem::update(GameObject* gameObject) {
    if(gameObject != nullptr) {
        RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
        if(renderComponent != nullptr) {
            TransformComponent* transform = gameObject->getTransform();
            SDL_Rect rect = renderComponent->getRectangle();
            rect.x = transform->getX();
            rect.y = transform->getY();
            SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(&renderer, &rect);
        }
    }
}
