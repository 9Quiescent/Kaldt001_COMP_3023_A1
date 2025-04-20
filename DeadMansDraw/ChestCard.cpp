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

void ChestCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
