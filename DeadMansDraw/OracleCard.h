#pragma once

#include "Card.h"
#include "OracleCardAbility.h"

class OracleCard : public Card {
public:
    OracleCard(int pointValue);
    ~OracleCard();

    void play(Player& player, Game& game) override;
};
