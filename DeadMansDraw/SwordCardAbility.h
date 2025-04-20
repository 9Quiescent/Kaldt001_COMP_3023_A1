#pragma once
#include "ICardAbility.h"

class SwordCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
