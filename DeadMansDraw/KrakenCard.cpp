#include "KrakenCard.h"

KrakenCard::KrakenCard()
    : Card(Suit::Kraken, 2, new KrakenCardAbility())
{
}

std::string KrakenCard::toString() const
{
    return "Kraken";
}
