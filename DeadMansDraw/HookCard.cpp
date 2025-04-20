#include "HookCard.h"

HookCard::HookCard()
    : Card(Suit::Hook, 5, new HookCardAbility())
{
}

std::string HookCard::toString() const
{
    return "Hook";
}
