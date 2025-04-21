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
#include <ctime>
#include <cstdlib>

GameController::GameController()
    : game(nullptr), playerController(nullptr)
{
}

GameController::~GameController()
{
    delete game;
    game = nullptr;
    delete playerController;
    playerController = nullptr;

}

void GameController::startGame()
{
    srand(static_cast<unsigned int>(time(0))); // Put this seed here so we don't just get the exact same name duo each time.

    game = new Game();
    playerController = new HumanPlayerController();

    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };

    std::string player1Name = names[rand() % 10];
    std::string player2Name = names[rand() % 10];

    while (player2Name == player1Name) {
        player2Name = names[rand() % 10];
    }

    Player* player1 = new Player(player1Name);
    Player* player2 = new Player(player2Name);

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
