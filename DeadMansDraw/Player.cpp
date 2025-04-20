#include "Player.h"

Player::Player() {
    // I'm going to put Player initialization logic here
}

Player::~Player() {
    // I'm going to put Player memory cleanup logic here
}

void Player::addToPlayArea(Card* card) {
    // I'm going to put logic to add a Card to the play area here
}

void Player::bankPlayArea() {
    // I'm going to put logic to move play area Cards to bank here
}

void Player::resetPlayArea() {
    // I'm going to put logic to clear the play area here
}

const std::vector<Card*>& Player::getBank() const {
    return bank;
}

const std::vector<Card*>& Player::getPlayArea() const {
    return playArea;
}
