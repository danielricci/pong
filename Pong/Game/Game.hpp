#pragma once

#include "Engine/Application.hpp"

class Game : public Application {
public:
    Game(const char* title, int width, int height);
    virtual ~Game();
    virtual void run() override;
};
