#include "SwordCard.h"

SwordCard::SwordCard(int pointValue)
    : Card(Suit::Sword, pointValue, new SwordCardAbility())
{
}

SwordCard::~SwordCard()
{
   
}

std::string SwordCard::toString() const
{
    return "Sword";
}

void SwordCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
