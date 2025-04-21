#pragma once

#include "Card.h"
#include "MapCardAbility.h"

class MapCard : public Card {
public:
    MapCard(int pointValue);
    ~MapCard();

    void play(Player& player, Game& game) override;
};
