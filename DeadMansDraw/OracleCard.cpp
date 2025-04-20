#include "OracleCard.h"

OracleCard::OracleCard(int pointValue)
    : Card(Suit::Oracle, pointValue, new OracleCardAbility())
{
}

std::string OracleCard::toString() const {
    return "Oracle";
}
