#include "AnchorCard.h"

AnchorCard::AnchorCard(int pointValue)
    : Card(Suit::Anchor, pointValue, CardType::Anchor, new AnchorCardAbility())
{
}

AnchorCard::~AnchorCard()
{
}

void AnchorCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
