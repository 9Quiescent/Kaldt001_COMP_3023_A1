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
    for (Card* card : deck) {
        delete card;
    }
    for (Player* player : players) {
        delete player;
    }
}

void Game::addPlayer(Player* player)
{
    players.push_back(player);
}

void Game::start()
{
    std::cout << "Starting Game..." << std::endl;

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
            for (Card* card : currentPlayer->getPlayArea()) {
                if (card != nullptr) {
                    std::cout << "  " << card->str() << std::endl;
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
                turnOver = true;
            }
            else if (choice == 'y' || choice == 'Y') {
               
            }
            else {
                std::cout << "Invalid input. Ending turn." << std::endl;
                bankCards(*currentPlayer);
                printBank(currentPlayer);
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
    CardCollection shuffleDeck{ deck.begin(), deck.end() };
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
    const std::vector<Card*>& playAreaBeforeBank = player.getPlayArea();

    for (Card* card : playAreaBeforeBank) {
        if (card != nullptr) {
            if (card->type() == Card::CardType::Chest) {
                hasChest = true;
            }
            if (card->type() == Card::CardType::Key) {
                hasKey = true;
            }
        }
    }

    // Only here do we finally bank the play area
    player.bankPlayArea();

    if (hasChest && hasKey) {
        std::cout << "Chest and Key activated. Adding bonus cards from discard pile to bank..." << std::endl;

        size_t bonusCardsToDraw = playAreaBeforeBank.size(); // Building up the bonus based on banked cards
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

    for (Card* card : playArea) {
        if (card == nullptr) continue;

        Suit suit = card->getSuit();

        if (suit == Suit::Anchor)
            hasAnchor = true;

        for (Suit s : seenSuits) {
            if (s == suit) {
                if (hasAnchor)
                    return false;
                else
                    return true;
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

    for (Card* card : playArea) {
        if (card == nullptr) continue;

        Suit suit = card->getSuit();
        if (suit == Suit::Anchor) {
            hasAnchor = true;
        }
        else {
            for (Suit s : seenSuits) {
                if (s == suit) {
                    if (hasAnchor) {
                        std::cout << "Anchor prevents bust (Anchor present)!" << std::endl;
                        for (Card* c : playArea) {
                            if (c != nullptr && c->getSuit() == Suit::Anchor) {
                                c->play(player, *this);
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
        for (Card* card : bank) {
            if (card != nullptr)
                std::cout << "  " << card->str() << std::endl;
        }
    }
}

bool Game::isDeckEmpty() const
{
    return deck.empty();
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
    int highestScore = 0;
    bool tie = false;

    for (Player* player : players) {
        int score = 0;
        for (Card* card : player->getBank()) {
            if (card != nullptr)
                score += card->getPointValue();
        }

        if (score > highestScore) {
            highestScore = score;
            winner = player;
            tie = false;
        }
        else if (score == highestScore && player != winner) {
            tie = true;
        }
    }

    if (tie)
        return nullptr;

    return winner;
}

void Game::addCardToDeck(Card* card)
{
    if (card != nullptr) {
        deck.push_back(card);
    }
}

const std::vector<Player*>& Game::getPlayers() const
{
    return players;
}

void Game::discardPlayArea(Player& player)
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    for (Card* card : playArea) {
        if (card != nullptr)
            discardPile.push_back(card);
    }

    player.resetPlayArea();
}

void Game::printFinalScores() const
{
    std::cout << "Game finished." << std::endl;
    std::cout << "\nFinal Scores:" << std::endl;

    for (Player* p : players) {
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

    Player* winner = getWinner();
    if (winner != nullptr)
        std::cout << "\nWinner is: " << winner->getName() << "!" << std::endl;
    else
        std::cout << "\nIt's a tie!" << std::endl;
}

const std::vector<Card*>& Game::getDiscardPile() const
{
    return discardPile;
}
