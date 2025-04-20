#pragma once
#include "ICardAbility.h"

class MermaidCardAbility : public ICardAbility
{
public:
    void apply(Game& game, Player& player);
};
