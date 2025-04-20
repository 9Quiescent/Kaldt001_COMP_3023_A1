#pragma once
#include "ICardAbility.h"

class KeyCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
