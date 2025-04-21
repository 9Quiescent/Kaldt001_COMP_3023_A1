#include "Card.h"

Card::Card(Suit suit, int pointValue, CardType cardType, ICardAbility* ability)
    : suit(suit), pointValue(pointValue), cardType(cardType), ability(ability)
{
}

Card::~Card()
{
    delete ability;
}

Suit Card::getSuit() const
{
    return suit;
}

int Card::getPointValue() const
{
    return pointValue;
}

const Card::CardType& Card::type() const
{
    return cardType;
}

std::string Card::getCardTypeAsString() const
{
    switch (cardType) {
    case CardType::Cannon: return "Cannon";
    case CardType::Chest: return "Chest";
    case CardType::Key: return "Key";
    case CardType::Anchor: return "Anchor";
    case CardType::Sword: return "Sword";
    case CardType::Hook: return "Hook";
    case CardType::Oracle: return "Oracle";
    case CardType::Map: return "Map";
    case CardType::Mermaid: return "Mermaid";
    case CardType::Kraken: return "Kraken";
    default: return "Unknown";
    }
}

std::string Card::str() const
{
    return getCardTypeAsString() + "(" + std::to_string(pointValue) + ")";
}
