#include "Player.h"
#include "Game.h"
#include <map>
#include <iostream>

Player::Player(const std::string& name)
    : name(name), game(nullptr), currentScore(0)
{
}

Player::~Player()
{
}

void Player::addToPlayArea(Card* card)
{
    if (card != nullptr) {
        playArea.push_back(card);
    }
}

void Player::bankPlayArea()
{
    for (size_t i = 0; i < playArea.size(); ++i) {
        if (playArea[i] != nullptr) {
            bank.push_back(playArea[i]);
        }
    }
    playArea.clear();
    updateScore(); // Update score after banking
}

void Player::resetPlayArea()
{
    playArea.clear();
}

const std::vector<Card*>& Player::getBank() const
{
    return bank;
}

const std::vector<Card*>& Player::getPlayArea() const
{
    return playArea;
}

std::string Player::getName() const
{
    return name;
}

void Player::addToBank(Card* card)
{
    if (card != nullptr) {
        bank.push_back(card);
        updateScore();
    }
}

void Player::setOpponent(Player* opponent)
{
    this->opponent = opponent;
}

Player* Player::getOpponent() const
{
    return opponent;
}

Card* Player::removeLastBankedCard()
{
    if (bank.empty())
        return nullptr;

    Card* stolenCard = bank.back();
    bank.pop_back();
    updateScore(); 
    return stolenCard;
}

void Player::setGame(Game* game)
{
    this->game = game;
}

Game* Player::getGame() const
{
    return game;
}

Card* Player::removeBankedCardAt(int index)
{
    if (index >= static_cast<int>(bank.size())) {
        return nullptr;
    }

    Card* removedCard = bank[index];
    bank.erase(bank.begin() + index);
    updateScore(); 
    return removedCard;
}

void Player::updateScore()
{
    std::map<Suit, int> highestPerSuit;
    for (size_t i = 0; i < bank.size(); ++i) {
        Card* card = bank[i];
        if (card != nullptr) {
            Suit suit = card->getSuit();
            int points = card->getPointValue();
            if (highestPerSuit.find(suit) == highestPerSuit.end() || points > highestPerSuit[suit]) {
                highestPerSuit[suit] = points;
            }
        }
    }

    currentScore = 0;
    for (std::map<Suit, int>::iterator it = highestPerSuit.begin(); it != highestPerSuit.end(); ++it) {
        currentScore += it->second;
    }
}

int Player::getCurrentScore() const
{
    return currentScore;
}

bool Player::checkBust() const
{
    bool hasAnchor = false;
    std::vector<Suit> seenSuits;

    for (size_t i = 0; i < playArea.size(); ++i) {
        Card* card = playArea[i];
        if (card == nullptr) continue;
        Suit suit = card->getSuit();
        if (suit == Suit::Anchor) hasAnchor = true;

        for (size_t j = 0; j < seenSuits.size(); ++j) {
            if (seenSuits[j] == suit) {
                return !hasAnchor; // Bust if no Anchor
            }
        }

        seenSuits.push_back(suit);
    }

    return false;
}

// Handle bust logic
bool Player::handleBust(Game& game)
{
    bool hasAnchor = false;
    std::vector<Suit> seenSuits;

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
                                playArea[k]->play(*this, game);
                                break;
                            }
                        }
                        return false;
                    }
                    else {
                        std::cout << "BUST! " << name << " loses all cards in play area." << std::endl;
                        game.discardPlayArea(*this);
                        return true;
                    }
                }
            }
            seenSuits.push_back(suit);
        }
    }

    return false;
}
