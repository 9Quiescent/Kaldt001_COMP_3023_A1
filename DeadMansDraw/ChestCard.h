#pragma once

#include "Card.h"
#include "ChestCardAbility.h"

class ChestCard : public Card {
public:
    ChestCard(int pointValue);
    ~ChestCard();
    std::string toString() const override;
    void play(Player& player, Game& game) override;
};
