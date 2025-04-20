#include "AnchorCard.h"

AnchorCard::AnchorCard()
    : Card(Suit::Anchor, 4, new AnchorCardAbility())
{
}

std::string AnchorCard::toString() const
{
    return "Anchor";
}
