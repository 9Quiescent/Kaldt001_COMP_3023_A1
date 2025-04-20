#pragma once
#include "Card.h"
#include "KrakenCardAbility.h"

class KrakenCard : public Card {
public:
    KrakenCard(int pointValue);
    std::string toString() const;
};
