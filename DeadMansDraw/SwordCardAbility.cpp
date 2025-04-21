#include "SwordCardAbility.h"
#include "Player.h"
#include "Card.h"
#include <iostream>

void SwordCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Sword Ability Activated: Attempting to steal a card from opponent's bank..." << std::endl;

    Player* opponent = player.getOpponent();
    if (opponent == nullptr)
    {
        std::cout << "No opponent found. Sword ability fails." << std::endl; //need this for debugging  while coding the targetting on this ability
        return;
    }

    const std::vector<Card*>& opponentBank = opponent->getBank();
    if (opponentBank.empty())
    {
        std::cout << "Opponent's bank is empty. No card to steal." << std::endl;
        return;
    }

    Card* stolenCard = opponent->removeLastBankedCard();
    if (stolenCard != nullptr)
    {
        player.addToPlayArea(stolenCard);
        std::cout << "Successfully stole " << stolenCard->str() << " from " << opponent->getName() << "'s bank and added it to your play area." << std::endl;
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
