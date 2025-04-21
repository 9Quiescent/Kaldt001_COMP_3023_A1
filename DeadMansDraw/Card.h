#pragma once

#include "Suit.h"
#include "ICardAbility.h"
#include <string>

class Player;
class Game;

class Card {
public:
    enum class CardType { Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken };

protected:
    int pointValue;
    Suit suit;
    CardType cardType;
    ICardAbility* ability;

public:
    Card(Suit suit, int pointValue, CardType cardType, ICardAbility* ability);
    virtual ~Card();

    Suit getSuit() const;
    int getPointValue() const;
    const CardType& type() const;

    std::string getCardTypeAsString() const;
    virtual std::string str() const;

    virtual void play(Player& player, Game& game) = 0;
    virtual void willAddToBank(Game& game, Player& player) {}
};
