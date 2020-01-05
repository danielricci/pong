#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/Components/TextRenderComponent.hpp"
#include "Game/Systems/RenderSystem.hpp"

#include <SDL.h>

void RenderSystem::update(GameObject* gameObject) {
    if(gameObject != nullptr) {
        RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
        if(renderComponent != nullptr) {
            SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
            TextComponent* textComponent = gameObject->getComponent<TextComponent>();
            TextRenderComponent* textRenderComponent = gameObject->getComponent<TextRenderComponent>();
            if (textComponent != nullptr && textRenderComponent != nullptr) {
                SDL_Rect rectangle = gameObject->getTransform()->rectangle();
                SDL_QueryTexture(textRenderComponent->getTexture(), nullptr, nullptr, &rectangle.w, &rectangle.h);
                SDL_RenderCopy(&renderer, textRenderComponent->getTexture(), nullptr, &rectangle);
            }
            else {
                SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
                SDL_Rect rectangle = gameObject->getTransform()->rectangle();
                SDL_RenderFillRect(&renderer, &rectangle);
            }
        }
    }
}
