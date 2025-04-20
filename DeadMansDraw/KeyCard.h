#pragma once
#include "Card.h"
#include "KeyCardAbility.h"

class KeyCard : public Card {
public:
    KeyCard(int pointValue);
    std::string toString() const;
};
