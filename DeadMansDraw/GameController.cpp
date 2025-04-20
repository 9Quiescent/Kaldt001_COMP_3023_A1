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
    // I'm going to setup the GameController here
}

GameController::~GameController()
{
    // I'm going to clean up the GameController here
    delete game;
    delete playerController;
}

void GameController::startGame() {
    game = new Game();
    playerController = new HumanPlayerController();

    Player* player1 = new Player("Billy");
    Player* player2 = new Player("Sasha");

    game->addPlayer(player1);
    game->addPlayer(player2);

    game->start(); 

    std::cout << "Setting up full deck..." << std::endl;

    for (int i = 0; i < 6; ++i) {
        game->addCardToDeck(new AnchorCard(5));    
        game->addCardToDeck(new CannonCard(4));
        game->addCardToDeck(new ChestCard(5));
        game->addCardToDeck(new HookCard(5));
        game->addCardToDeck(new KeyCard(5));
        game->addCardToDeck(new KrakenCard(6));
        game->addCardToDeck(new MapCard(3));
        game->addCardToDeck(new MermaidCard(5));
        game->addCardToDeck(new OracleCard(4));
        game->addCardToDeck(new SwordCard(5));
    }

    std::cout << "Starting sanity check..." << std::endl;

    int turnCount = 1;
    bool gameOver = false;

    while (!gameOver) {
        std::cout << "--- Round " << ((turnCount - 1) / 2) + 1 << ", Turn " << turnCount << " ---" << std::endl;

        Player* currentPlayer = game->getCurrentPlayer();
        std::cout << currentPlayer->getName() << "'s turn." << std::endl;

        game->printBank(currentPlayer);

        bool turnOver = false;
        while (!turnOver) {
            Card* drawnCard = game->drawCard();
            if (drawnCard == nullptr) {
                std::cout << "Game over! Deck is empty." << std::endl;
                gameOver = true;
                break;
            }

            std::cout << currentPlayer->getName() << " draws " << drawnCard->toString() << "!" << std::endl;

            currentPlayer->addToPlayArea(drawnCard);
            std::cout << currentPlayer->getName() << "'s Play Area:" << std::endl;
            for (Card* card : currentPlayer->getPlayArea()) {
                if (card != nullptr) {
                    std::cout << "  " << card->toString() << std::endl;
                }
            }

            // Check for bust
            if (game->checkBust(*currentPlayer)) {
                std::cout << "BUST! " << currentPlayer->getName() << " loses all cards in play area." << std::endl;
                currentPlayer->resetPlayArea();
                turnOver = true;
                break;
            }

            // Ask player if they want to draw again
            char choice;
            std::cout << "Draw again? (y/n): ";
            std::cin >> choice;

            if (choice == 'n' || choice == 'N') {
                game->bankCards(*currentPlayer);
                game->printBank(currentPlayer);
                turnOver = true;
            }
            else if (choice == 'y' || choice == 'Y') {
                // Player wants to draw again, so i'll just continue the loop
            }
            else {
                std::cout << "Invalid input, therefore 'no'. Turn End." << std::endl;
                game->bankCards(*currentPlayer);
                game->printBank(currentPlayer);
                turnOver = true;
            }
        }

        if (!gameOver) {
            game->nextTurn();
            ++turnCount;
        }
    }

    std::cout << "Game finished." << std::endl;
}

void GameController::promptPlayerAction()
{
    // I'm going to ask the player what action they want to take here
}
