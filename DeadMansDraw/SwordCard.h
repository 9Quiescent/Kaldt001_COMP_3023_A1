#pragma once
#include "Card.h"
#include "SwordCardAbility.h"

class SwordCard : public Card {
public:
    SwordCard(int pointValue);
    std::string toString() const;
};
