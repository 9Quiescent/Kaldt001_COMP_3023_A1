#include "CannonCard.h"

CannonCard::CannonCard(int pointValue)
    : Card(Suit::Cannon, pointValue, new CannonCardAbility())
{
}

std::string CannonCard::toString() const {
    return "Cannon";
}
