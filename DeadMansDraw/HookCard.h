#pragma once

#include "Card.h"
#include "HookCardAbility.h"

class HookCard : public Card {
public:
    HookCard(int pointValue);
    ~HookCard();

    void play(Player& player, Game& game) override;
};
