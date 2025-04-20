#pragma once
#include "Suit.h"
#include "ICardAbility.h"
#include <string>

class Card
{
protected:
    Suit suit;
    int pointValue;
    ICardAbility* ability;

public:
    Card(Suit suit, int pointValue, ICardAbility* ability);
    virtual ~Card();
    Suit getSuit() const;
    int getPointValue() const;
    virtual std::string toString() const = 0;
};
