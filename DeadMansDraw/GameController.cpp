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
#include <cstdlib> 
#include <ctime>

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

    srand(time(0)); 

    std::string possibleNames[] = {
        "Billy", "Sasha", "Mira", "Leo", "Nina", "Dante", "Aria", "Kai"
    };
    const int nameCount = sizeof(possibleNames) / sizeof(possibleNames[0]);

    std::string name1 = possibleNames[rand() % nameCount];
    std::string name2 = possibleNames[rand() % nameCount];

    while (name1 == name2) {
        name2 = possibleNames[rand() % nameCount];
    }

    Player* player1 = new Player(name1);
    Player* player2 = new Player(name2);

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
