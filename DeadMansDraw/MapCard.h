#pragma once
#include "Card.h"
#include "MapCardAbility.h"
#include "Player.h"

class MapCard : public Card {
public:
    MapCard(int pointValue);
    ~MapCard();
    std::string toString() const override;
    void play(Player& player) override;
};
