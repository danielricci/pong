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

#include "Game/Components/RenderComponent.hpp"
#include "Game/Components/TextComponent.hpp"
#include "Game/Components/TextRenderComponent.hpp"
#include "Game/Systems/RenderSystem.hpp"

#include <SDL.h>

void RenderSystem::update(GameObject* gameObject) {
    if(gameObject != nullptr) {
        RenderComponent* renderComponent = gameObject->getComponent<RenderComponent>();
        if(renderComponent != nullptr && renderComponent->isVisible) {
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
