#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/Systems/RenderSystem.hpp"

#include <SDL.h>

void RenderSystem::update(GameObject* gameObject) {
    if(gameObject != nullptr) {
        RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
        if(renderComponent != nullptr) {
            SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
            TextComponent* textComponent = gameObject->getComponent<TextComponent>();
            if (textComponent != nullptr) {
                
                
                
                
                //surface = TTF_RenderText_Blended(font, text.c_str(), { 255, 255, 255 });
                //SDL_Texture* texture = SDL_CreateTextureFromSurface(&renderer, textSurface);
                //SDL_Rect rectangle = gameObject->getTransform()->rectangle();
                //SDL_QueryTexture(texture, nullptr, nullptr, &rectangle.w, &rectangle.h);
                
                //SDL_RenderCopy(&renderer, texture, nullptr, &rectangle);
            }
            else {
                SDL_SetRenderDrawColor(&renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
                SDL_Rect rectangle = gameObject->getTransform()->rectangle();
                SDL_RenderFillRect(&renderer, &rectangle);
            }
        }
    }
}
