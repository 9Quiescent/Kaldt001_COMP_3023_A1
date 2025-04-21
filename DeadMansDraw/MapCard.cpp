#include "MapCard.h"

MapCard::MapCard(int pointValue)
    : Card(Suit::Map, pointValue, CardType::Map, new MapCardAbility())
{
}

MapCard::~MapCard()
{
}

void MapCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
