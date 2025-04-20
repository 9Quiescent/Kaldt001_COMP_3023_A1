#pragma once

#include <string>

class Player;
class Card;

class ICardAbility {
public:
    virtual ~ICardAbility() = default;
    virtual void apply(Card& card, Player& player) = 0;
    virtual std::string toString() const = 0;
};
