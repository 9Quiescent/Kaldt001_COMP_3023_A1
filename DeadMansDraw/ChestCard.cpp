#include "ChestCard.h"

ChestCard::ChestCard(int pointValue)
    : Card(Suit::Chest, pointValue, new ChestCardAbility())
{
}

ChestCard::~ChestCard()
{
    
}

std::string ChestCard::toString() const
{
    return "Chest";
}

void ChestCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
