#include "MapCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void MapCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Map Ability Activated: DUROOOOO, 3 cards from discard pile!" << std::endl;

    Game* game = player.getGame();
    if (game == nullptr)
    {
        std::cout << "Error: Game pointer is nothingness. Map ability fails." << std::endl;
        return;
    }

    const std::vector<Card*>& discardPile = game->getDiscardPile();
    if (discardPile.empty())
    {
        std::cout << "No cards available in discard pile. Map ability does nothing." << std::endl;
        return;
    }

    // Pick up to 3 cards
    int numberToShow = discardPile.size() < 3 ? static_cast<int>(discardPile.size()) : 3;
    std::vector<Card*> shownCards;

    std::cout << "Available cards from discard pile:" << std::endl;
    for (int i = 0; i < numberToShow; ++i)
    {
        // Show most recent discarded cards (last elements)
        Card* shownCard = discardPile[discardPile.size() - 1 - i];
        if (shownCard != nullptr)
        {
            shownCards.push_back(shownCard);
            std::cout << i << ": " << shownCard->str() << std::endl;
        }
    }

    // Player must choose one
    int choice = 0;
    std::cout << "Enter index of card to play: ";
    std::cin >> choice;

    if (choice < 0 || choice >= shownCards.size())
    {
        std::cout << "Invalid choice. Defaulting to first card." << std::endl;
        choice = 0;
    }

    Card* selectedCard = shownCards[choice];

    if (selectedCard != nullptr)
    {
        // Remove selected card from discard pile
        int discardIndex = discardPile.size() - 1 - choice;
        Card* removedCard = game->removeFromDiscardPileAt(discardIndex);

        if (removedCard != nullptr)
        {
            player.addToPlayArea(removedCard);
            std::cout << "Added " << removedCard->str() << " from discard pile to play area!" << std::endl;
        }
        else
        {
            std::cout << "Error: Unexpected behaviour while removing selected card from discard pile." << std::endl;
        }
    }
    else
    {
        std::cout << "Selected card was null. No action taken." << std::endl;
    }
}

std::string MapCardAbility::toString() const
{
    return "Map Ability";
}
