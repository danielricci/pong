#pragma once

#include "Game/Components/Component.hpp"

#include <SDL_mixer.h>

#include <string>

class SoundComponent : public Component {
public:
    SoundComponent(const std::string& path);
    ~SoundComponent();
    
    void play() const;
private:
    Mix_Chunk* chunk { nullptr };
    const std::string& path;
};
