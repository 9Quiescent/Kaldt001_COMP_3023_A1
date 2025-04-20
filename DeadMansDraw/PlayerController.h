#pragma once

#include "Player.h"

class PlayerController {
public:
    virtual ~PlayerController() = default;
    virtual bool wantsToDraw(const Player& player) = 0;
};
