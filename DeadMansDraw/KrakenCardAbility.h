#pragma once
#include "ICardAbility.h"

class KrakenCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
