#include "GameController.h"

GameController::GameController()
    : game(nullptr), playerController(nullptr) 
{
    // I'm going to setup the GameController here
}

GameController::~GameController() {
    // I'm going to clean up the GameController here
}

void GameController::startGame()
{
    game = new Game();
    playerController = new HumanPlayerController();

    // Create two players
    Player* player1 = new Player("Player 1");
    Player* player2 = new Player("Player 2");

    // Add players to the game
    game->addPlayer(player1);
    game->addPlayer(player2);

    std::cout << "Game setup complete. Two players ready!" << std::endl; //Doing a sanity check here....

    game->start();
}

void GameController::promptPlayerAction() {
    // I'm going to ask the player what action they want to take here
}
