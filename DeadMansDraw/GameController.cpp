#include "GameController.h"
#include "ChestCard.h"
#include "SwordCard.h"
#include "MapCard.h"
#include "AnchorCard.h"
#include "CannonCard.h"
#include "HookCard.h"
#include "KeyCard.h"
#include "KrakenCard.h"
#include "MermaidCard.h"
#include "OracleCard.h"
#include <iostream>

GameController::GameController()
    : game(nullptr), playerController(nullptr)
{
}

GameController::~GameController()
{
    delete game;
    delete playerController;
}

void GameController::startGame()
{
    game = new Game();
    playerController = new HumanPlayerController();

    Player* player1 = new Player("Billy");
    Player* player2 = new Player("Sasha");

    player1->setOpponent(player2);
    player2->setOpponent(player1);

    game->addPlayer(player1);
    game->addPlayer(player2);

    game->start();
}

void GameController::promptPlayerAction()
{
    // Implement depending on time
}
