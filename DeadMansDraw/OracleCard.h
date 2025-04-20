#pragma once
#include "Card.h"
#include "OracleCardAbility.h"

class OracleCard : public Card
{
public:
    OracleCard();
    std::string toString() const;
};
