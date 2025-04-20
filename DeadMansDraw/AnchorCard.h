#pragma once
#include "Card.h"
#include "AnchorCardAbility.h"

class AnchorCard : public Card {
public:
    AnchorCard(int pointValue);
    std::string toString() const;
};
