#include "SwordCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void SwordCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Sword Ability Activated: Attempting to steal a card from opponent's bank..." << std::endl;

    Player* opponent = player.getOpponent();
    if (opponent == nullptr) {
        std::cout << "No opponent found. Sword ability fails." << std::endl;
        return;
    }

    const std::vector<Card*>& opponentBank = opponent->getBank();
    if (opponentBank.empty()) {
        std::cout << "Opponent's bank is empty. No card to steal." << std::endl;
        return;
    }

    // See CannonCardAbility
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

    // See CannonCardAbility
    std::vector<int> highestValueIndexes;
    for (int i = 0; i < opponentBank.size(); ++i)
    {
        if (opponentBank[i] != nullptr && opponentBank[i]->getPointValue() == highestValue)
        {
            highestValueIndexes.push_back(i);
        }
    }

    // See CannonCardAbility
    std::cout << "Choose a card to steal from opponent's bank:" << std::endl;
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
        std::cin.ignore(10000, '\n'); //God forbid they do over 10000 characters that are misinputs lol
        std::cout << "Invalid input (non-number)! Defaulting to first option." << std::endl;
        choice = 0;
    }
    else if (choice < 0 || choice >= highestValueIndexes.size()) {
        std::cout << "Invalid choice. Defaulting to first option." << std::endl;
        choice = 0;
    }

    // Again, very similar, but we steal instead of destroy ("discard")
    int bankIndex = highestValueIndexes[choice];
    Card* stolenCard = opponent->removeBankedCardAt(bankIndex);
    if (stolenCard != nullptr)
    {
        player.addToPlayArea(stolenCard);
        std::cout << "Successfully stole " << stolenCard->str() << " from opponent's bank and added it to your play area." << std::endl;
    }
    else
    {
        std::cout << "Unexpected error: No card stolen." << std::endl;
    }
}

std::string SwordCardAbility::toString() const
{
    return "Sword Ability";
}
