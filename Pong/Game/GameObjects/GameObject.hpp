#pragma once

#include "Game/Components/Component.hpp"
#include "Game/Components/TransformComponent.hpp"

#include <SDL.h>

#include <list>

class GameObject {
public:
    template<typename T> T* getComponent() const {
        for(Component* component : components) {
            // TODO replace with get type if required
            T* myComponent = dynamic_cast<T*>(component);
            if(myComponent != nullptr) {
                return myComponent;
            }
        }
        return nullptr;
    }
    
    void addComponent(Component* const component) { components.push_back(component); }
    TransformComponent* getTransform() const { return transformComponent; }
    
protected:
    GameObject();
    GameObject(int x, int y);
    virtual ~GameObject();
    
private:
    std::list<Component*> components;
    TransformComponent* transformComponent = new TransformComponent();
};
