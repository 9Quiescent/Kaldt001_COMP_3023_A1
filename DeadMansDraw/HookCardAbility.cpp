#include "HookCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void HookCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Hook Ability Activated: Attempting to pull top card from discard pile..." << std::endl;

    Game* game = player.getGame();
    if (game == nullptr) {
        std::cout << "Error: couldn't find a game" << std::endl; //For future me, this is fixed, but keep the debug here.
        return;
    }

    Card* topDiscard = game->drawFromDiscardPile();
    if (topDiscard == nullptr) {
        std::cout << "Discard pile is empty. Hook ability has no effect." << std::endl;
        return;
    }

    std::cout << "Used le hook to swipe " << topDiscard->str() << " from discard pile into play area!" << std::endl;

    player.addToPlayArea(topDiscard);
}

std::string HookCardAbility::toString() const
{
    return "Hook Ability";
}
