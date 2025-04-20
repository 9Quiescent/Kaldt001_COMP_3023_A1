#pragma once
#include "Card.h"
#include "SwordCardAbility.h"

class SwordCard : public Card
{
public:
    SwordCard();
    std::string toString() const;
};
