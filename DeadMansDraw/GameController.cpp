#include "GameController.h"
#include "ChestCard.h"
#include "SwordCard.h"
#include "MapCard.h"

GameController::GameController()
    : game(nullptr), playerController(nullptr) 
{
    // I'm going to setup the GameController here
}

GameController::~GameController() {
    // I'm going to clean up the GameController here
}

void GameController::startGame() {
    game = new Game();
    playerController = new HumanPlayerController();

    Player* player1 = new Player("Billy");
    Player* player2 = new Player("Sasha");

    game->addPlayer(player1);
    game->addPlayer(player2);

    std::cout << "Manually setting up dummy deck..." << std::endl;
    game->addCardToDeck(new ChestCard(5));
    game->addCardToDeck(new SwordCard(3));
    game->addCardToDeck(new MapCard(2));

    std::cout << "Starting sanity check..." << std::endl;

    // Now manually draw cards
    Card* drawn = game->drawCard();
    if (drawn) {
        std::cout << "Drawn Card: " << drawn->toString() << std::endl;
        player1->addToPlayArea(drawn);
    }

    drawn = game->drawCard();
    if (drawn) {
        std::cout << "Drawn Card: " << drawn->toString() << std::endl;
        player2->addToPlayArea(drawn);
    }

    // Print play areas
    std::cout << player1->getName() << "'s Play Area:" << std::endl;
    for (Card* c : player1->getPlayArea()) {
        std::cout << "  " << c->toString() << std::endl;
    }

    std::cout << player2->getName() << "'s Play Area:" << std::endl;
    for (Card* c : player2->getPlayArea()) {
        std::cout << "  " << c->toString() << std::endl;
    }

    // Bank player1's cards
    game->bankCards(*player1);
    std::cout << player1->getName() << "'s Bank after banking:" << std::endl;
    game->printBank(player1);

    std::cout << "Is deck empty? " << (game->isDeckEmpty() ? "Yes" : "No") << std::endl;

    delete game;
    delete playerController;
}


void GameController::promptPlayerAction() {
    // I'm going to ask the player what action they want to take here
}
