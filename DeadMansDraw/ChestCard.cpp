#include "ChestCard.h"

ChestCard::ChestCard(int pointValue)
    : Card(Suit::Chest, pointValue, CardType::Chest, new ChestCardAbility())
{
}

ChestCard::~ChestCard()
{
}

void ChestCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
