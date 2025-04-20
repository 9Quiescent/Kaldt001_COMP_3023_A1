#pragma once
#include "Card.h"
#include "CannonCardAbility.h"
#include "Player.h"

class CannonCard : public Card {
public:
    CannonCard(int pointValue);
    ~CannonCard();
    std::string toString() const override;
    void play(Player& player) override;
};
