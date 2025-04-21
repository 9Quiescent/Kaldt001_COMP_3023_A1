#include "ChestCardAbility.h"
#include "Player.h"
#include "Card.h"
#include <iostream>

void ChestCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Chest Ability Activated: Checking for Key..." << std::endl;

    const std::vector<Card*>& playArea = player.getPlayArea();
    bool hasKey = false;

    for (Card* c : playArea) {
        if (c != nullptr && c->type() == Card::CardType::Key) {
            hasKey = true;
            break;
        }
    }

    if (hasKey) {
        std::cout << "Key detected! Chest and Key combo ready." << std::endl;
    }
    else {
        std::cout << "No Key detected. No bonus triggered." << std::endl;
    }
}

std::string ChestCardAbility::toString() const
{
    return "Chest Ability";
}
