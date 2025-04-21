#pragma once

#include "Card.h"
#include "KrakenCardAbility.h"

class KrakenCard : public Card {
public:
    KrakenCard(int pointValue);
    ~KrakenCard();

    void play(Player& player, Game& game) override;
};
