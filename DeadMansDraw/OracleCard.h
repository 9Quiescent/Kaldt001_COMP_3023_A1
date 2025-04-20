#pragma once
#include "Card.h"
#include "OracleCardAbility.h"
#include "Player.h"

class OracleCard : public Card {
public:
    OracleCard(int pointValue);
    ~OracleCard();
    std::string toString() const override;
    void play(Player& player) override;
};
