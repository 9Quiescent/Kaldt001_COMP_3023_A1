#include "OracleCard.h"

OracleCard::OracleCard(int pointValue)
    : Card(Suit::Oracle, pointValue, CardType::Oracle, new OracleCardAbility())
{
}

OracleCard::~OracleCard()
{
}

void OracleCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
