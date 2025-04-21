#include "KrakenCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void KrakenCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Kraken Ability Activated: Must draw and play three cards consecutively!" << std::endl;

    Game* game = player.getGame();
    if (game == nullptr)
    {
        std::cout << "Error: Game not found for player." << std::endl;
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (game->isDeckEmpty())
        {
            std::cout << "Warning: Deck is empty. Cannot draw more cards for Kraken." << std::endl;
            break;
        }

        Card* drawnCard = game->drawCard();
        if (drawnCard == nullptr)
        {
            std::cout << "Error: Failed to draw a card for Kraken." << std::endl;
            break;
        }

        std::cout << player.getName() << " draws " << drawnCard->str() << "!" << std::endl;

        player.addToPlayArea(drawnCard);
        drawnCard->play(player, *game);

        if (game->handleBust(player))
        {
            std::cout << "Bust occurred! Kraken ability ends immediately." << std::endl;
            break;
        }
    }
}

std::string KrakenCardAbility::toString() const
{
    return "Kraken Ability";
}
