#pragma once
#include "Card.h"
#include "MermaidCardAbility.h"

class MermaidCard : public Card
{
public:
    MermaidCard();
    std::string toString() const;
};
