#pragma once
#include "ICardAbility.h"

class MapCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
