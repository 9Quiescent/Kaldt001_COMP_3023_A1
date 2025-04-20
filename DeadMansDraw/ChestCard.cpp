#include "ChestCard.h"

ChestCard::ChestCard(int pointValue)
    : Card(Suit::Chest, pointValue, new ChestCardAbility())
{
}

std::string ChestCard::toString() const {
    return "Chest";
}
