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
    const std::vector<Card*>& playArea = player.getPlayArea();

    if (playArea.empty()) {
        std::cout << "No cards to bank." << std::endl;
        return;
    }

    std::cout << "Added ";

    for (size_t i = 0; i < playArea.size(); ++i) {
        if (playArea[i] != nullptr)
        {
            std::cout << playArea[i]->toString();
            if (i != playArea.size() - 1)
                std::cout << ", ";
        }
    }

    std::cout << " to your bank." << std::endl;

    player.bankPlayArea(); // Cards might actually move around now hey?
}

bool Game::checkBust(const Player& player) const
{
    const std::vector<Card*>& playArea = player.getPlayArea();
    bool hasAnchor = false;
    std::vector<Suit> seenSuits;

    for (Card* card : playArea)
    {
        if (card == nullptr) continue;

        Suit suit = card->getSuit();

        if (suit == Suit::Anchor)
            hasAnchor = true;

        for (Suit s : seenSuits)
        {
            if (s == suit)
            {
                if (hasAnchor)
                {
                    std::cout << "Anchor prevents bust (Anchor present)!" << std::endl;
                    return false; // Whenever they are saved from embarrassment by the anchor
                }
                else
                {
                    return true; // When there is no anchor to save them
                }
            }
        }

        seenSuits.push_back(suit);
    }

    return false; // Bust doesn't happen
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
    bool tie = false;

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
            tie = false; 
        }
        else if (score == highestScore && player != winner)
        {
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
