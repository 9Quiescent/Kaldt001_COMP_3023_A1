#pragma once
#include "Card.h"
#include "ChestCardAbility.h"

class ChestCard : public Card
{
public:
    ChestCard();
    std::string toString() const;
};
