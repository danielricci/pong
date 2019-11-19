#pragma once

#include "Game/Application.hpp"

class Game : public Application {
public:
    Game();
    virtual ~Game() = default;
    virtual void run() override;
};
