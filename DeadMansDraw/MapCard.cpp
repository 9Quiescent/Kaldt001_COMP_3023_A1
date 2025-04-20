#include "MapCard.h"

MapCard::MapCard(int pointValue)
    : Card(Suit::Map, pointValue, new MapCardAbility())
{
}

std::string MapCard::toString() const {
    return "Map";
}
