#pragma once
#include "ICardAbility.h"

class HookCardAbility : public ICardAbility {
public:
    void apply(Card& card, Player& player) override;
    std::string toString() const override;
};
