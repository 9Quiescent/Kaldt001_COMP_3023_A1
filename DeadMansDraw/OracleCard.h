#pragma once
#include "Card.h"
#include "OracleCardAbility.h"

class OracleCard : public Card {
public:
    OracleCard(int pointValue);
    std::string toString() const;
};
