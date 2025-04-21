#pragma once

#include <vector>
#include <string>
#include "Card.h"

class Player {

private:
    Player* opponent = nullptr;
    Game* game;
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
    void setOpponent(Player* opponent);
    Player* getOpponent() const;
    Card* removeLastBankedCard();
    void setGame(Game* game);
    Game* getGame() const;
    Card* removeBankedCardAt(int index);
    bool isBust() const;



};