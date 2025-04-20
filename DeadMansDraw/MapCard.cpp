#include "MapCard.h"

MapCard::MapCard(int pointValue)
    : Card(Suit::Map, pointValue, new MapCardAbility())
{
}

MapCard::~MapCard()
{
}

std::string MapCard::toString() const
{
    return "Map";
}

void MapCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
