#pragma once

#include <vector>
#include "Player.h"
#include "Card.h"

class Game {
private:
    std::vector<Player*> players;
    std::vector<Card*> deck;
    int currentPlayerIndex;
    bool gameOver;

public:
    Game();
    ~Game();

    void addPlayer(Player* player);
    void start();
    void nextTurn();
    Card* drawCard();
    void bankCards(Player& player);
    bool checkBust(const Player& player) const;
    void printBank(Player* player) const;
    bool isDeckEmpty() const;
    Player* getCurrentPlayer() const;
    Player* getWinner() const;
    void addCardToDeck(Card* card);

};
