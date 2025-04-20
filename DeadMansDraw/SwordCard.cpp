#include "SwordCard.h"

SwordCard::SwordCard(int pointValue)
    : Card(Suit::Sword, pointValue, new SwordCardAbility())
{
}

std::string SwordCard::toString() const {
    return "Sword";
}
