#include "CannonCard.h"

CannonCard::CannonCard()
    : Card(Suit::Cannon, 5, new CannonCardAbility())
{
}

std::string CannonCard::toString() const
{
    return "Cannon";
}
