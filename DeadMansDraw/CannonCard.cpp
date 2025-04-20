#include "CannonCard.h"

CannonCard::CannonCard(int pointValue)
    : Card(Suit::Cannon, pointValue, new CannonCardAbility())
{
}

CannonCard::~CannonCard()
{
}

std::string CannonCard::toString() const
{
    return "Cannon";
}

void CannonCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
