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

#pragma once

#include "Game/Components/Component.hpp"
#include "Game/Components/TransformComponent.hpp"

#include <list>

class GameObject {
public:

    virtual ~GameObject();

    template<typename T> T* getComponent() const {
        T* myComponent { nullptr };
        for(Component* component : components) {
            if((myComponent = component->getComponent<T>()) != nullptr) {
                break;
            }
        }
        return myComponent;
    }
    
    Component* addComponent(Component* component);
    TransformComponent* getTransform() const;

protected:
    GameObject(int x = 0, int y = 0, int width = 0, int height = 0);
    
private:
    std::list<Component*> components;
    TransformComponent* transformComponent { nullptr };
};
