#include "KeyCard.h"

KeyCard::KeyCard()
    : Card(Suit::Key, 7, new KeyCardAbility())
{
}

std::string KeyCard::toString() const
{
    return "Key";
}
