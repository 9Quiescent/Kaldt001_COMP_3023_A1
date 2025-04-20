#include "Card.h"

Card::Card(Suit suit, int pointValue, ICardAbility* ability)
    : suit(suit), pointValue(pointValue), ability(ability)
{
}

Card::~Card() {
    delete ability;
}

Suit Card::getSuit() const {
    return suit;
}

int Card::getPointValue() const {
    return pointValue;
}
