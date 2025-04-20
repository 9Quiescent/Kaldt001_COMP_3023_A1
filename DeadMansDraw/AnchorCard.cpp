#include "AnchorCard.h"

AnchorCard::AnchorCard(int pointValue)
    : Card(Suit::Anchor, pointValue, new AnchorCardAbility())
{
}

AnchorCard::~AnchorCard()
{
}

std::string AnchorCard::toString() const
{
    return "Anchor";
}

void AnchorCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
