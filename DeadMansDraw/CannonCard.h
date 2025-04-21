#pragma once

#include "Card.h"
#include "CannonCardAbility.h"

class CannonCard : public Card {
public:
    CannonCard(int pointValue);
    ~CannonCard();

    void play(Player& player, Game& game) override;
};
