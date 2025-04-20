#pragma once
#include "ICardAbility.h"

class OracleCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
