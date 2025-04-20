#include "HookCard.h"

HookCard::HookCard(int pointValue)
    : Card(Suit::Hook, pointValue, new HookCardAbility())
{
}

HookCard::~HookCard()
{
    
}

std::string HookCard::toString() const
{
    return "Hook";
}

void HookCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
