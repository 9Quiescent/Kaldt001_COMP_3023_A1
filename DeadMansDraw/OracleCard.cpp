#include "OracleCard.h"

OracleCard::OracleCard(int pointValue)
    : Card(Suit::Oracle, pointValue, new OracleCardAbility())
{
}

OracleCard::~OracleCard()
{
   
}

std::string OracleCard::toString() const
{
    return "Oracle";
}

void OracleCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
