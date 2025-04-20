#pragma once

#include "Card.h"
#include "MermaidCardAbility.h"

class MermaidCard : public Card {
public:
    MermaidCard(int pointValue);
    ~MermaidCard();
    std::string toString() const override;
    void play(Player& player, Game& game) override;
};
