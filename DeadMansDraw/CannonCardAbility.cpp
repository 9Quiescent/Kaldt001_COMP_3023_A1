#include "CannonCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void CannonCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Cannon Ability Activated: Attempting to destroy a card from opponent's bank..." << std::endl;

    Player* opponent = player.getOpponent();
    if (opponent == nullptr) {
        std::cout << "No opponent found. Cannon ability fails." << std::endl;
        return;
    }

    const std::vector<Card*>& opponentBank = opponent->getBank();
    if (opponentBank.empty()) {
        std::cout << "Opponent's bank is empty. No card to destroy!" << std::endl;
        return;
    }

    // Iterate through bank and reassign the highest value until there are no more elemenets.
    int highestValue = 0;
    for (int i = 0; i < opponentBank.size(); ++i)
    {
        if (opponentBank[i] != nullptr)
        {
            int value = opponentBank[i]->getPointValue();
            if (value > highestValue)
            {
                highestValue = value;
            }
        }
    }

    // Iterate through elements with said highest value
    std::vector<int> highestValueIndexes;
    for (int i = 0; i < opponentBank.size(); ++i)
    {
        if (opponentBank[i] != nullptr && opponentBank[i]->getPointValue() == highestValue)
        {
            highestValueIndexes.push_back(i);
        }
    }

    // Give player a selection from those options
    std::cout << "Choose a card to destroy from opponent's bank:" << std::endl;
    for (int i = 0; i < highestValueIndexes.size(); ++i)
    {
        int idx = highestValueIndexes[i];
        if (opponentBank[idx] != nullptr)
        {
            std::cout << i << ": " << opponentBank[idx]->str() << std::endl;
        }
    }

    int choice = 0;
    std::cout << "Enter choice index: ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input (non-number)! Defaulting to first option." << std::endl;
        choice = 0;
    }
    else if (choice < 0 || choice >= opponentBank.size()) {
        std::cout << "Invalid choice. Defaulting to first option." << std::endl;
        choice = 0;
    }

    // Actually destroy the  inputted item. If they missclick, as seen above destroy the default.
    int bankIndex = highestValueIndexes[choice];
    Card* destroyedCard = opponent->removeBankedCardAt(bankIndex);
    if (destroyedCard != nullptr)
    {
        player.getGame()->addToDiscardPile(destroyedCard); 
        std::cout << "Successfully destroyed " << destroyedCard->str() << " from opponent's bank, straight to the discard pile!" << std::endl;
    }
    else
    {
        std::cout << "Unexpected error: No card destroyed." << std::endl;
    }
}

std::string CannonCardAbility::toString() const
{
    return "Cannon Ability";
}
