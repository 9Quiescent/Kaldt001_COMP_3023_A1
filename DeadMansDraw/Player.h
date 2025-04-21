#pragma once

#include <vector>
#include <string>
#include "Card.h"

class Player {
protected:
    std::string name;
    std::vector<Card*> bank;
    std::vector<Card*> playArea;

public:
    Player(const std::string& name);
    ~Player();

    void addToPlayArea(Card* card);
    void bankPlayArea();
    void resetPlayArea();
    const std::vector<Card*>& getBank() const;
    const std::vector<Card*>& getPlayArea() const;
    std::string getName() const;
    void addToBank(Card* card);

};
