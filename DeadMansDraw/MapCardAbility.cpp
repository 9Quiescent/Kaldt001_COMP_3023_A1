#include "MapCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void MapCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Map Ability Activated: Search up to 3 cards from the discard pile!" << std::endl;

    Game* game = player.getGame();
    if (game == nullptr)
    {
        std::cout << "Error: Game pointer is null. Map ability fails." << std::endl;
        return;
    }

    const std::vector<Card*>& discardPile = game->getDiscardPile();
    if (discardPile.empty())
    {
        std::cout << "No cards available in discard pile. Map ability does nothing." << std::endl;
        return;
    }

    int numberToShow = discardPile.size() < 3 ? static_cast<int>(discardPile.size()) : 3;
    std::vector<Card*> shownCards;

    std::cout << "Available cards from discard pile:" << std::endl;
    for (int i = 0; i < numberToShow; ++i)
    {
        Card* shownCard = discardPile[discardPile.size() - 1 - i];
        if (shownCard != nullptr)
        {
            shownCards.push_back(shownCard);
            std::cout << i << ": " << shownCard->str() << std::endl;
        }
    }

    int choice = 0;
    std::cout << "Enter index of card to play: ";
    std::cin >> choice;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n'); //Same junk clearing tactic i've used throughout
        std::cout << "Invalid input (non-number)! Defaulting to first option." << std::endl;
        choice = 0;
    }
    else if (choice < 0 || choice >= shownCards.size())
    {
        std::cout << "Invalid choice. Defaulting to first option." << std::endl;
        choice = 0;
    }

   
    Card* selectedCard = shownCards[choice];
    if (selectedCard != nullptr)
    {
        // Put selected card on the current player's play area.
        player.addToPlayArea(selectedCard);
        std::cout << "Added " << selectedCard->str() << " from discard pile to play area!" << std::endl;
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
