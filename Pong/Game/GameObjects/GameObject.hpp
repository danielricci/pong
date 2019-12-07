#pragma once

#include "Game/Components/Component.hpp"
#include "Game/Components/TransformComponent.hpp"

#include <list>

class GameObject {
public:

    virtual ~GameObject();

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
    GameObject(int x = 0, int y = 0);
    
private:
    std::list<Component*> components;
    TransformComponent* transformComponent { nullptr };
};
