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
    // I'm going to add the card to the play area here
}

void Player::bankPlayArea() {
    // I'm going to bank the play area cards here
}

void Player::resetPlayArea() {
    // I'm going to reset the play area here
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
