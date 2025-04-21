#pragma once

#include <vector>
#include <string>
#include "Card.h"

class Game;

class Player {
private:
    Player* opponent = nullptr;
    Game* game;
    std::string name;
    std::vector<Card*> bank;
    std::vector<Card*> playArea;
    int currentScore = 0;

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
    void updateScore();            
    int getCurrentScore() const;  
    bool checkBust() const;
    bool handleBust(Game& game);
};
