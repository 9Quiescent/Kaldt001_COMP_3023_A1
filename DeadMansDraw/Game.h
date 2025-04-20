#pragma once

#include <vector>
#include "Card.h"
#include "Player.h"

class Game {
private:
    std::vector<Card*> deck;
    std::vector<Card*> discardPile;
    std::vector<Player*> players;
    int currentPlayerIndex;

public:
    Game();
    ~Game();

    void start();
    void nextPlayer();
    void addPlayer(Player* player);
    Card* drawCard();
    void discardCard(Card* card);
};
