#pragma once

#include <vector>
#include "Card.h"

class Player {
protected:
    std::vector<Card*> bank;
    std::vector<Card*> playArea;

public:
    Player();
    ~Player();
    void addToPlayArea(Card* card);
    void bankPlayArea();
    void resetPlayArea();
    const std::vector<Card*>& getBank() const;
    const std::vector<Card*>& getPlayArea() const;
};
