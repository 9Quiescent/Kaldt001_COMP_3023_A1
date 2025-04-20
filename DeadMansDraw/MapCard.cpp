#include "MapCard.h"

MapCard::MapCard()
    : Card(Suit::Map, 5, new MapCardAbility())
{
}

std::string MapCard::toString() const
{
    return "Map";
}
