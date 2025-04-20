#include "Game.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "AnchorCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include "KrakenCard.h"
#include "OracleCard.h"

#include <algorithm> 
#include <iostream> 

Game::Game()
    : currentPlayerIndex(0) // Gonna initialise it here
{
    // I'm going to setup the starting state here
}

Game::~Game()
{
    // I'm going to clean up dynamic memory here
}

void Game::start()
{
    // Create all cards and push into deck
    deck.push_back(new CannonCard(2));
    deck.push_back(new ChestCard(2));
    deck.push_back(new KeyCard(2));
    deck.push_back(new SwordCard(2));
    deck.push_back(new HookCard(2));
    deck.push_back(new AnchorCard(2));
    deck.push_back(new MapCard(2));
    deck.push_back(new MermaidCard(2));
    deck.push_back(new KrakenCard(2));
    deck.push_back(new OracleCard(2));
    /*
    * // Print pre shuffle
    std::cout << "Before shuffle:" << std::endl;
    for (Card* card : deck) {
        std::cout << card->toString() << std::endl;
    }

    //Sep prints with newline
    std::cout << std::endl;

    // Shuffle the pre shuffle
    std::random_shuffle(deck.begin(), deck.end());

    // Print the after shuffle
    std::cout << "After shuffle:" << std::endl;
    for (Card* card : deck) {
        std::cout << card->toString() << std::endl;
    }
    */
    
}

void Game::nextPlayer()
{
    // I'm going to implement the player switching logic here
}

void Game::addPlayer(Player* player)
{
    // I'm going to add a player here
}

Card* Game::drawCard()
{
    // I'm going to draw a card here
    return nullptr;
}

void Game::discardCard(Card* card)
{
    // I'm going to discard a card here
}
