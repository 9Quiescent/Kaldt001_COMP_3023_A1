#pragma once
#include "Card.h"
#include "MapCardAbility.h"

class MapCard : public Card
{
public:
    MapCard();
    std::string toString() const;
};
