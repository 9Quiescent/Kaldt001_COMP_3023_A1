#include "Game.h"
#include <iostream>
#include <vector>

Game::Game()
    : currentPlayerIndex(0), gameOver(false)
{
    // I'm going to initialize the game here
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
    std::cout << "Game::start() called" << std::endl;
    
}

void Game::nextTurn()
{
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

Card* Game::drawCard()
{
    if (deck.empty())
    {
        std::cout << "Warning: Deck is empty, cannot draw a card." << std::endl;
        return nullptr;
    }

    Card* card = deck.back();
    deck.pop_back();
    return card;
}

void Game::bankCards(Player& player)
{
    std::cout << "Game::bankCards() called" << std::endl;
    player.bankPlayArea();
}

bool Game::checkBust(const Player& player) const
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    std::vector<Suit> seenSuits; // Using vector instead of set

    for (Card* card : playArea)
    {
        if (card == nullptr) continue;

        Suit suit = card->getSuit();

        // Linear search: check if suit was already seen
        bool duplicateFound = false;
        for (Suit s : seenSuits)
        {
            if (s == suit)
            {
                duplicateFound = true;
                break;
            }
        }

        if (duplicateFound)
        {
            // Duplicate suit found, player busts
            return true;
        }

        seenSuits.push_back(suit);
    }

    return false; // No duplicates, safe
}

void Game::printBank(Player* player) const
{
    if (player == nullptr) return;

    const std::vector<Card*>& bank = player->getBank();

    std::cout << player->getName() << "'s Bank:" << std::endl;
    if (bank.empty())
    {
        std::cout << "  (empty)" << std::endl;
    }
    else
    {
        for (Card* card : bank)
        {
            if (card != nullptr)
                std::cout << "  " << card->toString() << std::endl;
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

    for (Player* player : players)
    {
        int score = 0;
        for (Card* card : player->getBank())
        {
            if (card != nullptr)
                score += card->getPointValue();
        }

        if (score > highestScore)
        {
            highestScore = score;
            winner = player;
        }
    }

    return winner;
}

void Game::addCardToDeck(Card* card)
{
    if (card != nullptr) {
        deck.push_back(card);
    }
}
