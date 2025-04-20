#include "AnchorCardAbility.h"
#include <iostream>
#include "Player.h"

void AnchorCardAbility::apply(Card& card, Player& player)
{
    std::cout << "Anchor Ability Activated: Banking current Play Area safely!" << std::endl;

    player.bankPlayArea();

    // This portion is for showing what was banked by the ability
    const std::vector<Card*>& bank = player.getBank();
    std::cout << "Added ";
    for (size_t i = 0; i < bank.size(); ++i)
    {
        if (bank[i] != nullptr)
        {
            std::cout << bank[i]->toStringWithPoints();
            if (i != bank.size() - 1)
                std::cout << ", ";
        }
    }
    std::cout << " to your bank." << std::endl;
}


std::string AnchorCardAbility::toString() const
{
    return "Anchor Ability";
}
