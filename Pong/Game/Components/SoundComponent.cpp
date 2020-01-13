#include "Game/Components/SoundComponent.hpp"

#include <iostream>

SoundComponent::SoundComponent(const std::string& path) : path(path) {
    chunk = Mix_LoadWAV(path.c_str());
    if(chunk == nullptr) {
        std::cerr << "Could not load sound at path " << path << "because of error:" << Mix_GetError() << std::endl;
    }
}

SoundComponent::~SoundComponent() {
    if(chunk != nullptr) {
        Mix_FreeChunk(chunk);
        chunk = nullptr;
    }
}

void SoundComponent::play() const {
    if(chunk != nullptr) {
        Mix_PlayChannel(-1, chunk, 0);        
    }
    else {
        std::cerr << "Could not play sound, invalid chunk" << std::endl;
    }
}
