#pragma once
#include "Card.h"
#include "KrakenCardAbility.h"
#include "Player.h"

class KrakenCard : public Card {
public:
    KrakenCard(int pointValue);
    ~KrakenCard();
    std::string toString() const override;
    void play(Player& player) override;
};
