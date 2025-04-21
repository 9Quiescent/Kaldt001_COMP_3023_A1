#include "OracleCardAbility.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

void OracleCardAbility::apply(Card& card, Player& player)
{
    const std::vector<Card*>& deck = player.getGame()->getDeck();

    if (!deck.empty())
    {
        Card* topCard = deck.back(); //back is first card btw future me.

        if (topCard != nullptr)
        {
            std::cout << "Oracle Ability Activated: The next card to be drawn is "
                << topCard->str() << "." << std::endl;
        }
    }
    else
    {
        std::cout << "Oracle Ability Activated: No cards left in the deck to peek at." << std::endl;
    }
}

std::string OracleCardAbility::toString() const
{
    return "Oracle Ability";
}
