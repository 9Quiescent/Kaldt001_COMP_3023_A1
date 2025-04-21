#include "HookCard.h"

HookCard::HookCard(int pointValue)
    : Card(Suit::Hook, pointValue, CardType::Hook, new HookCardAbility())
{
}

HookCard::~HookCard()
{
}

void HookCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
