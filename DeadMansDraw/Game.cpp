#include "Game.h"
#include "AnchorCard.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "HookCard.h"
#include "KeyCard.h"
#include "KrakenCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include "OracleCard.h"
#include "SwordCard.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>

Game::Game()
    : currentPlayerIndex(0), gameOver(false)
{
}

Game::~Game()
{
    for (size_t i = 0; i < deck.size(); ++i) {
        delete deck[i];
    }
    for (size_t i = 0; i < discardPile.size(); ++i) {
        delete discardPile[i];
    }
    for (size_t i = 0; i < players.size(); ++i) {
        delete players[i];
    }
}

void Game::addPlayer(Player* player)
{
    if (player != nullptr) {
        player->setGame(this);
        players.push_back(player);
    }
}

void Game::start()
{
    std::cout << R"(______                  _   ___  ___              _
|  _  \                | |  |  \/  |             ( )
| | | | ___   __ _   __| |  | .  . |  __ _  _ __ |/ ___
| | | |/ _ \ / _` | / _` |  | |\/| | / _` || '_ \  / __|
| |/ /|  __/| (_| || (_| |  | |  | || (_| || | | | \__ \
|___/  \___| \__,_| \__,_|  \_|  |_/ \__,_||_| |_| |___/
|  _  \                         _      _
| | | | _ __  __ _ __      __ _| |_  _| |_
| | | || '__|/ _` |\ \ /\ / /|_   _||_   _|
| |/ / | |  | (_| | \ V  V /   |_|    |_|
|___/  |_|   \__,_|  \_/\_/)" << std::endl;

    std::cout << "\nStarting Dead Man's Draw++!" << std::endl;

    for (int i = 0; i < 6; ++i) {
        addCardToDeck(new AnchorCard(5));
        addCardToDeck(new CannonCard(4));
        addCardToDeck(new ChestCard(5));
        addCardToDeck(new HookCard(5));
        addCardToDeck(new KeyCard(5));
        addCardToDeck(new KrakenCard(6));
        addCardToDeck(new MapCard(3));
        addCardToDeck(new MermaidCard(5));
        addCardToDeck(new OracleCard(4));
        addCardToDeck(new SwordCard(5));
    }

    shuffleDeck();

    int turnCount = 1;
    gameOver = false;

    while (!gameOver) {
        std::cout << "--- Round " << ((turnCount - 1) / 2) + 1 << ", Turn " << turnCount << " ---" << std::endl;

        Player* currentPlayer = getCurrentPlayer();
        if (currentPlayer == nullptr) {
            std::cout << "Error: No current player." << std::endl;
            break;
        }

        std::cout << currentPlayer->getName() << "'s turn." << std::endl;
        printBank(currentPlayer);
        std::cout << currentPlayer->getName() << "'s Current Score: " << currentPlayer->getCurrentScore() << std::endl;

        bool turnOver = false;
        while (!turnOver) {
            Card* drawnCard = drawCard();
            if (drawnCard == nullptr) {
                std::cout << "Game over! Deck is empty." << std::endl;
                gameOver = true;
                break;
            }

            std::cout << currentPlayer->getName() << " draws " << drawnCard->str() << "!" << std::endl;
            currentPlayer->addToPlayArea(drawnCard);

            if (drawnCard->shouldPlayImmediately()) {
                drawnCard->play(*currentPlayer, *this);
            }

            std::cout << currentPlayer->getName() << "'s Play Area:" << std::endl;
            const std::vector<Card*>& playArea = currentPlayer->getPlayArea();
            for (size_t i = 0; i < playArea.size(); ++i) {
                if (playArea[i] != nullptr) {
                    std::cout << "  " << playArea[i]->str() << std::endl;
                }
            }

            if (handleBust(*currentPlayer)) {
                turnOver = true;
                break;
            }

            char choice;
            std::cout << "Draw again? (y/n): ";
            std::cin >> choice;

            if (choice == 'n' || choice == 'N') {
                bankCards(*currentPlayer);
                printBank(currentPlayer);
                std::cout << currentPlayer->getName() << "'s Current Score: " << currentPlayer->getCurrentScore() << std::endl;
                turnOver = true;
            }
            else if (choice == 'y' || choice == 'Y') {
                // continue
            }
            else {
                std::cout << "Invalid input. Ending turn." << std::endl;
                bankCards(*currentPlayer);
                printBank(currentPlayer);
                std::cout << currentPlayer->getName() << "'s Current Score: " << currentPlayer->getCurrentScore() << std::endl;
                turnOver = true;
            }
        }

        if (!gameOver) {
            nextTurn();
            ++turnCount;
        }
    }

    printFinalScores();
}

void Game::shuffleDeck()
{
    CardCollection shuffleDeck(deck.begin(), deck.end());
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), deck.begin());
}

void Game::nextTurn()
{
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

Card* Game::drawCard()
{
    if (deck.empty()) {
        std::cout << "Warning: Deck is empty." << std::endl;
        return nullptr;
    }

    Card* card = deck.back();
    deck.pop_back();
    return card;
}

void Game::bankCards(Player& player)
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    if (playArea.empty()) {
        std::cout << "No cards to bank." << std::endl;
        return;
    }

    std::cout << "Added ";
    for (size_t i = 0; i < playArea.size(); ++i) {
        if (playArea[i] != nullptr) {
            std::cout << playArea[i]->str();
            if (i != playArea.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << " to your bank." << std::endl;

    bool hasChest = false;
    bool hasKey = false;

    for (size_t i = 0; i < playArea.size(); ++i) {
        if (playArea[i] != nullptr) {
            if (playArea[i]->type() == Card::CardType::Chest) {
                hasChest = true;
            }
            if (playArea[i]->type() == Card::CardType::Key) {
                hasKey = true;
            }
        }
    }

    player.bankPlayArea();

    if (hasChest && hasKey) {
        std::cout << "Chest and Key activated. Adding bonus cards from discard pile to bank..." << std::endl;
        size_t bonusCardsToDraw = playArea.size();
        for (size_t i = 0; i < bonusCardsToDraw && !discardPile.empty(); ++i) {
            Card* bonusCard = discardPile.back();
            discardPile.pop_back();
            if (bonusCard != nullptr) {
                std::cout << "  Bonus: " << bonusCard->str() << std::endl;
                player.addToBank(bonusCard);
            }
        }
    }
}

bool Game::checkBust(const Player& player) const
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    bool hasAnchor = false;
    std::vector<Suit> seenSuits;

    for (size_t i = 0; i < playArea.size(); ++i) {
        Card* card = playArea[i];
        if (card == nullptr) continue;
        Suit suit = card->getSuit();
        if (suit == Suit::Anchor) hasAnchor = true;
        for (size_t j = 0; j < seenSuits.size(); ++j) {
            if (seenSuits[j] == suit) {
                return !hasAnchor;
            }
        }
        seenSuits.push_back(suit);
    }

    return false;
}

bool Game::handleBust(Player& player)
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    std::vector<Suit> seenSuits;
    bool hasAnchor = false;

    for (size_t i = 0; i < playArea.size(); ++i) {
        Card* card = playArea[i];
        if (card == nullptr) continue;
        Suit suit = card->getSuit();
        if (suit == Suit::Anchor) {
            hasAnchor = true;
        }
        else {
            for (size_t j = 0; j < seenSuits.size(); ++j) {
                if (seenSuits[j] == suit) {
                    if (hasAnchor) {
                        std::cout << "Anchor prevents bust!" << std::endl;
                        for (size_t k = 0; k < playArea.size(); ++k) {
                            if (playArea[k] != nullptr && playArea[k]->getSuit() == Suit::Anchor) {
                                playArea[k]->play(player, *this);
                                break;
                            }
                        }
                        return false;
                    }
                    else {
                        std::cout << "BUST! " << player.getName() << " loses all cards in play area." << std::endl;
                        discardPlayArea(player);
                        return true;
                    }
                }
            }
            seenSuits.push_back(suit);
        }
    }
    return false;
}

void Game::printBank(Player* player) const
{
    if (player == nullptr) return;
    const std::vector<Card*>& bank = player->getBank();
    std::cout << player->getName() << "'s Bank:" << std::endl;
    if (bank.empty()) {
        std::cout << "  (empty)" << std::endl;
    }
    else {
        for (size_t i = 0; i < bank.size(); ++i) {
            if (bank[i] != nullptr) {
                std::cout << "  " << bank[i]->str() << std::endl;
            }
        }
    }
}

void Game::printFinalScores() const
{
    std::cout << "\nFinal Scores:" << std::endl;
    for (size_t i = 0; i < players.size(); ++i) {
        Player* player = players[i];
        if (player != nullptr) {
            std::cout << player->getName() << ": " << player->getCurrentScore() << " points" << std::endl;
        }
    }

    Player* winner = getWinner();
    if (winner != nullptr) {
        std::cout << "\nWinner is: " << winner->getName() << "!" << std::endl;
    }
    else {
        std::cout << "\nIt's a tie!" << std::endl;
    }
}

Player* Game::getCurrentPlayer() const
{
    if (players.empty()) return nullptr;
    return players[currentPlayerIndex];
}

Player* Game::getWinner() const
{
    if (players.empty()) return nullptr;
    Player* winner = players[0];
    int highestScore = winner->getCurrentScore();
    bool tie = false;

    for (size_t i = 1; i < players.size(); ++i) {
        int score = players[i]->getCurrentScore();
        if (score > highestScore) {
            highestScore = score;
            winner = players[i];
            tie = false;
        }
        else if (score == highestScore) {
            tie = true;
        }
    }

    if (tie) return nullptr;
    return winner;
}

bool Game::isDeckEmpty() const
{
    return deck.empty();
}

const std::vector<Card*>& Game::getDiscardPile() const
{
    return discardPile;
}

const std::vector<Card*>& Game::getDeck() const
{
    return deck;
}

const std::vector<Player*>& Game::getPlayers() const
{
    return players;
}

void Game::addCardToDeck(Card* card)
{
    if (card != nullptr) {
        deck.push_back(card);
    }
}

void Game::addToDiscardPile(Card* card)
{
    if (card != nullptr) {
        discardPile.push_back(card);
    }
}

void Game::discardPlayArea(Player& player)
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    for (size_t i = 0; i < playArea.size(); ++i) {
        if (playArea[i] != nullptr) {
            discardPile.push_back(playArea[i]);
        }
    }
    player.resetPlayArea();
}

Card* Game::drawFromDiscardPile()
{
    if (discardPile.empty()) {
        return nullptr;
    }
    Card* card = discardPile.back();
    discardPile.pop_back();
    return card;
}
