#pragma once

#include "PlayerController.h"

class HumanPlayerController : public PlayerController {
public:
    HumanPlayerController();
    ~HumanPlayerController();

    bool wantsToDraw(const Player& player) override;
};
