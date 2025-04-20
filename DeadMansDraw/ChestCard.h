#pragma once
#include "Card.h"
#include "ChestCardAbility.h"

class ChestCard : public Card {
public:
    ChestCard(int pointValue);
    std::string toString() const;
};
