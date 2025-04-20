#pragma once
#include "Card.h"
#include "MapCardAbility.h"

class MapCard : public Card {
public:
    MapCard(int pointValue);
    std::string toString() const;
};
