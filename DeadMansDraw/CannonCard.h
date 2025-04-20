#pragma once
#include "Card.h"
#include "CannonCardAbility.h"

class CannonCard : public Card
{
public:
    CannonCard();
    std::string toString() const;
};
