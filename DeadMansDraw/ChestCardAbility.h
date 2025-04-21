#pragma once

#include "ICardAbility.h"

class ChestCardAbility : public ICardAbility {
public:
    void apply(Card& card, Player& player) override;
    std::string toString() const override;
};
