#pragma once
#include "Card.h"
#include "HookCardAbility.h"

class HookCard : public Card
{
public:
    HookCard();
    std::string toString() const;
};
