#include "AnchorCard.h"

AnchorCard::AnchorCard(int pointValue)
    : Card(Suit::Anchor, pointValue, new AnchorCardAbility())
{
}

std::string AnchorCard::toString() const {
    return "Anchor";
}
