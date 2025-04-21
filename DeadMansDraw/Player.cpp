#include "Player.h"

Player::Player(const std::string& name)
    : name(name)
{
    // I'm going to initialise the bank and playArea vectors here
}

Player::~Player() {
    // I'm going to clean up any dynamic memory here if needed
}

void Player::addToPlayArea(Card* card) {
    if (card != nullptr) {
        playArea.push_back(card);
    }
}

void Player::bankPlayArea() {
    for (Card* card : playArea) {
        if (card != nullptr) {
            bank.push_back(card);
        }
    }
    playArea.clear();
}

void Player::resetPlayArea() {
    playArea.clear(); // Ownage stays stays with Game, don't have to delete here
}

const std::vector<Card*>& Player::getBank() const {
    return bank;
}

const std::vector<Card*>& Player::getPlayArea() const {
    return playArea;
}

std::string Player::getName() const {
    return name;
}

void Player::addToBank(Card* card)
{
    if (card != nullptr)
        bank.push_back(card);
}

void Player::setOpponent(Player* opponent) {
    this->opponent = opponent;
}

Player* Player::getOpponent() const {
    return opponent;
}

Card* Player::removeLastBankedCard() {
    if (bank.empty())
        return nullptr;

    Card* stolenCard = bank.back();
    bank.pop_back();
    return stolenCard;
}

