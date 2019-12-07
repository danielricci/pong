#include "Game/Systems/RenderSystem.hpp"
#include "Game/Components/RenderComponent.hpp"

#include <SDL.h>

RenderSystem::RenderSystem(SDL_Renderer& renderer) : renderer(renderer) {
}

SDL_Rect RenderSystem::mergeRectangles(const SDL_Rect& r1, const SDL_Rect& r2) const {
    SDL_Rect rectangle;
    rectangle.x = r1.x + r2.x;
    rectangle.y = r1.y + r2.y;
    rectangle.w = r1.w + r2.w;
    rectangle.h = r1.h + r2.h;
    return rectangle;
}

void RenderSystem::update(GameObject* gameObject) {
    if(gameObject != nullptr) {
        RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
        if(renderComponent != nullptr) {
            SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
            SDL_Rect rectangle = mergeRectangles(gameObject->getTransform()->rectangle(), renderComponent->rectangle());
            SDL_RenderFillRect(&renderer, &rectangle);
        }
    }
}
