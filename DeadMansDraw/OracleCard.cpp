#include "OracleCard.h"

OracleCard::OracleCard()
    : Card(Suit::Oracle, 3, new OracleCardAbility())
{
}

std::string OracleCard::toString() const
{
    return "Oracle";
}
