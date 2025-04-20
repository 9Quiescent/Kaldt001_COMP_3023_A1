#pragma once
#include "Card.h"
#include "KeyCardAbility.h"

class KeyCard : public Card
{
public:
    KeyCard();
    std::string toString() const;
};
