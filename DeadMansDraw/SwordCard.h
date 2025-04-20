#pragma once
#include "Card.h"
#include "SwordCardAbility.h"
#include "Player.h"

class SwordCard : public Card {
public:
    SwordCard(int pointValue);
    ~SwordCard();
    std::string toString() const override;
    void play(Player& player) override;
};
