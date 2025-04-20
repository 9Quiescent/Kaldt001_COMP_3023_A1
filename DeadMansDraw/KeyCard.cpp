#include "KeyCard.h"

KeyCard::KeyCard(int pointValue)
    : Card(Suit::Key, pointValue, new KeyCardAbility())
{
}

KeyCard::~KeyCard()
{
    
}

std::string KeyCard::toString() const
{
    return "Key";
}

void KeyCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
