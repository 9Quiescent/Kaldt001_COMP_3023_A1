#pragma once
#include "ICardAbility.h"

class KrakenCardAbility : public ICardAbility {
public:
    void apply(Card& card, Player& player) override;
    std::string toString() const override;
};
