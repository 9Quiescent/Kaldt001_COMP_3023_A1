#include "SwordCard.h"

SwordCard::SwordCard()
    : Card(Suit::Sword, 6, new SwordCardAbility())
{
}

std::string SwordCard::toString() const
{
    return "Sword";
}
