#pragma once

#include "Card.h"
#include "AnchorCardAbility.h"

class AnchorCard : public Card {
public:
    AnchorCard(int pointValue);
    ~AnchorCard();
    std::string toString() const override;
    void play(Player& player, Game& game) override;
};
