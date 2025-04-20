#pragma once
#include "ICardAbility.h"

class HookCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
