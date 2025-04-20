#pragma once
#include "Card.h"
#include "HookCardAbility.h"

class HookCard : public Card {
public:
    HookCard(int pointValue);
    std::string toString() const;
};
