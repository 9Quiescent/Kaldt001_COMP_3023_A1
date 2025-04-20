#include "Game.h"

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
    // I'm going to implement the game start logic here
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
