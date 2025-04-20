#pragma once

#include "Card.h"
#include "HookCardAbility.h"

class HookCard : public Card {
public:
    HookCard(int pointValue);
    ~HookCard();
    std::string toString() const override;
    void play(Player& player, Game& game) override;
};
