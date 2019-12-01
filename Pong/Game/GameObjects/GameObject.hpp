#pragma once

#include "Game/Components/Component.hpp"
#include "Game/Components/TransformComponent.hpp"

#include <list>

class GameObject {
public:
    template<typename T> T* getComponent() const {
        for(Component* component : components) {
            T* myComponent = dynamic_cast<T*>(component);
            if(myComponent != nullptr) {
                return myComponent;
            }
        }
        return nullptr;
    }
    
    Component* addComponent(Component* component);
    TransformComponent* getTransform() const;
    
protected:
    GameObject();
    GameObject(int x, int y);
    virtual ~GameObject();
    
private:
    std::list<Component*> components;
    TransformComponent* transformComponent = new TransformComponent();
};
