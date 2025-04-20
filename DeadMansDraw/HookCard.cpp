#include "HookCard.h"

HookCard::HookCard(int pointValue)
    : Card(Suit::Hook, pointValue, new HookCardAbility())
{
}

std::string HookCard::toString() const {
    return "Hook";
}
