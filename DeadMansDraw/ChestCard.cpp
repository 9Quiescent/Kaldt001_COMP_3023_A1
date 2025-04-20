#include "ChestCard.h"

ChestCard::ChestCard()
    : Card(Suit::Chest, 6, new ChestCardAbility())
{
}

std::string ChestCard::toString() const
{
    return "Chest";
}
