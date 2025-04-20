#pragma once
#include "Card.h"
#include "MermaidCardAbility.h"

class MermaidCard : public Card {
public:
    MermaidCard(int pointValue);
    std::string toString() const;
};
