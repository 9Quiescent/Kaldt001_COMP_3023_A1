#pragma once
#include "Card.h"
#include "CannonCardAbility.h"

class CannonCard : public Card {
public:
    CannonCard(int pointValue);
    std::string toString() const;
};
