#pragma once
#include "ICardAbility.h"

class CannonCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
