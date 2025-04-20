#pragma once
#include "Suit.h"
#include "ICardAbility.h"
#include <string>

class Player;

class Card {
protected:
    int pointValue;
    Suit suit;
    ICardAbility* ability;

public:
    Card(Suit suit, int pointValue, ICardAbility* ability);
    virtual ~Card();

    Suit getSuit() const;
    int getPointValue() const;

    virtual std::string toString() const = 0;
    virtual std::string toStringWithPoints() const;
    virtual void play(Player& player) = 0;
};
