#pragma once
#include "Card.h"
#include "KeyCardAbility.h"
#include "Player.h"

class KeyCard : public Card {
public:
    KeyCard(int pointValue);
    ~KeyCard();
    std::string toString() const override;
    void play(Player& player) override;
};
