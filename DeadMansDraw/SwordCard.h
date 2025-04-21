#pragma once

#include "Card.h"
#include "SwordCardAbility.h"

class SwordCard : public Card {
public:
    SwordCard(int pointValue);
    ~SwordCard();
    void play(Player& player, Game& game) override;
};
