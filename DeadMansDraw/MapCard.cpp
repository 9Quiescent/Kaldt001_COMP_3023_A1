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

void MapCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
