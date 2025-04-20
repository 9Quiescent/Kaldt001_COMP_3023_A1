#pragma once

#include "Game.h"
#include "HumanPlayerController.h"
#include <iostream>

class GameController {
private:
    Game* game;
    PlayerController* playerController;

public:
    GameController();
    ~GameController();

    void startGame();
    void promptPlayerAction();
};
