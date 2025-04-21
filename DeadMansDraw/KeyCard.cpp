#include "KeyCard.h"

KeyCard::KeyCard(int pointValue)
    : Card(Suit::Key, pointValue, CardType::Key, new KeyCardAbility())
{
}

KeyCard::~KeyCard()
{
}

void KeyCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
