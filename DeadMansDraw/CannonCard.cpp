#include "CannonCard.h"

CannonCard::CannonCard(int pointValue)
    : Card(Suit::Cannon, pointValue, CardType::Cannon, new CannonCardAbility())
{
}

CannonCard::~CannonCard()
{
}

void CannonCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
