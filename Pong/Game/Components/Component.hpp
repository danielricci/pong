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

#include <list>

class Component {
public:
    virtual ~Component() {
        for(Component* component : components) {
            delete component;
        }
        components.clear();
    }
    template<typename T> T* getComponent() {
        T* myComponent { dynamic_cast<T*>(this) };
        if(myComponent == nullptr) {
            for(Component* component : components) {
                myComponent = dynamic_cast<T*>(component);
                if(myComponent != nullptr) {
                    break;
                }
            }
        }
        return myComponent;
    }
    
    Component* addComponent(Component* component) {
        if(component != nullptr) {
            components.push_back(component);
        }
        return component;
    }
    
    bool enabled { true };
    
private:
    std::list<Component*> components;
};
