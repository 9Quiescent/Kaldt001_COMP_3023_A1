#include "SwordCard.h"

SwordCard::SwordCard(int pointValue)
    : Card(Suit::Sword, pointValue, CardType::Sword, new SwordCardAbility())
{
}

SwordCard::~SwordCard()
{
}

void SwordCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
