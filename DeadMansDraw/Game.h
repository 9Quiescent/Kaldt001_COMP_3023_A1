#pragma once

#include <vector>
#include "Player.h"
#include "Card.h"

class Game {
private:
    std::vector<Player*> players;
    std::vector<Card*> deck;
    std::vector<Card*> discardPile;
    int currentPlayerIndex;
    bool gameOver;

public:
    Game();
    ~Game();

    void addPlayer(Player* player);
    void start();
    void shuffleDeck();
    void nextTurn();
    Card* drawCard();
    void bankCards(Player& player);
    bool checkBust(const Player& player) const;
    bool handleBust(Player& player);
    void discardPlayArea(Player& player);
    void printBank(Player* player) const;
    void printFinalScores() const;
    bool isDeckEmpty() const;
    Player* getCurrentPlayer() const;
    Player* getWinner() const;
    void addCardToDeck(Card* card);
    const std::vector<Player*>& getPlayers() const;
    const std::vector<Card*>& getDiscardPile() const;
    const std::vector<Card*>& getDeck() const;
    void addToDiscardPile(Card* card);
    Card* drawFromDiscardPile();

};
