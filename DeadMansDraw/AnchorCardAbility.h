#pragma once
#include "ICardAbility.h"

class AnchorCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
