#pragma once

#include "Card.h"
#include "AnchorCardAbility.h"

class AnchorCard : public Card {
public:
    AnchorCard(int pointValue);
    ~AnchorCard();
    void play(Player& player, Game& game) override;
    bool shouldPlayImmediately() const override { return false; }
};
