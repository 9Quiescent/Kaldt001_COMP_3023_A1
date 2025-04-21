#pragma once

#include "Card.h"
#include "ChestCardAbility.h"

class ChestCard : public Card {
public:
    ChestCard(int pointValue);
    ~ChestCard();
    void play(Player& player, Game& game) override;
    bool shouldPlayImmediately() const override { return false; }
};
