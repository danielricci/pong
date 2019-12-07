#pragma once

#include "Game/Components/Component.hpp"

#include <SDL.h>

#include <unordered_map>
#include <string>

class InputComponent : public Component {

public:
    InputComponent() = default;
    
    void addBindings(SDL_Keycode keyCode, const std::string& action) {
        inputBindings[keyCode] = action;
    }
    
    void handleEvent(const SDL_Event& event) {
        InputBindingsMap::const_iterator inputIterator = inputBindings.find(event.key.keysym.sym);
        if(inputIterator != inputBindings.end()) {
            ActionBindingsMap::const_iterator actionIterator = actionBindings.find(inputIterator->second);
            if(actionIterator != actionBindings.end()) {
                actionIterator->second(event);
            }
        }
    }
    
    virtual Type identifier() const override {
        return Component::Type::InputComponent;
    }

    void registerActionBinding(const std::string& action, std::function<void(const SDL_Event&)> functor) {
        actionBindings[action] = functor;
    }
    
private:
    typedef std::unordered_map<SDL_Keycode, std::string> InputBindingsMap;
    InputBindingsMap inputBindings;
    
    typedef std::unordered_map<std::string, std::function<void(const SDL_Event&)>> ActionBindingsMap;
    ActionBindingsMap actionBindings;
};
