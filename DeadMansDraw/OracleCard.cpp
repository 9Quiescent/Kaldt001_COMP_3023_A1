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

void OracleCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
