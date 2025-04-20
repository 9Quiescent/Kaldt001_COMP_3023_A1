#include "KeyCard.h"

KeyCard::KeyCard(int pointValue)
    : Card(Suit::Key, pointValue, new KeyCardAbility())
{
}

std::string KeyCard::toString() const {
    return "Key";
}
