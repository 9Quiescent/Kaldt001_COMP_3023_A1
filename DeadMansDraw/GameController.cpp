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

            std::cout << currentPlayer->getName() << " draws " << drawnCard->toStringWithPoints() << "!" << std::endl;

            currentPlayer->addToPlayArea(drawnCard);
            std::cout << currentPlayer->getName() << "'s Play Area:" << std::endl;
            for (Card* card : currentPlayer->getPlayArea()) {
                if (card != nullptr) {
                    std::cout << "  " << card->toStringWithPoints() << std::endl;
                }
            }

            // Check for bust
            if (HandleBust(currentPlayer)) {
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
    std::cout << "\nFinal Scores:" << std::endl;

    const std::vector<Player*>& allPlayers = game->getPlayers();

    for (Player* p : allPlayers) {
        if (p != nullptr) {
            int score = 0;
            const std::vector<Card*>& bank = p->getBank();
            for (Card* card : bank) {
                if (card != nullptr)
                    score += card->getPointValue();
            }
            std::cout << p->getName() << ": " << score << " points" << std::endl;
        }
    }

    // Announce the winner
    Player* winner = game->getWinner();
    if (winner != nullptr) {
        std::cout << "\nWinner is: " << winner->getName() << "!" << std::endl;
    }
    else {
        std::cout << "\nIt's a tie!" << std::endl;
    }
}

void GameController::promptPlayerAction()
{
    // I'm going to ask the player what action they want to take here
}

bool GameController::HandleBust(Player* player)
{
    const std::vector<Card*>& playArea = player->getPlayArea();
    std::vector<Suit> seenSuits;
    bool hasAnchor = false;

    for (Card* card : playArea)
    {
        if (card == nullptr) continue;

        Suit suit = card->getSuit();
        if (suit == Suit::Anchor)
        {
            hasAnchor = true;
        }
        else
        {
            for (Suit s : seenSuits)
            {
                if (s == suit)
                {
                    if (hasAnchor)
                    {
                        std::cout << "Anchor prevents bust (Anchor present)!" << std::endl;

                        // Look around for the anchor, activate its ability
                        for (Card* c : playArea)
                        {
                            if (c != nullptr && c->getSuit() == Suit::Anchor)
                            {
                                c->play(*player); // This activates the anchor ability (apply), from the anchor card that composes it
                                break; 
                            }
                        }

                        return false; // Bust didn't occur
                    }
                    else
                    {
                        std::cout << "BUST! " << player->getName() << " loses all cards in play area." << std::endl;
                        game->discardPlayArea(*player);;
                        return true; // Bust did occur
                    }
                }
            }
            seenSuits.push_back(suit);
        }
    }

    return false; // No bust detected
}

