#include "KrakenCard.h"

KrakenCard::KrakenCard(int pointValue)
    : Card(Suit::Kraken, pointValue, new KrakenCardAbility())
{
}

std::string KrakenCard::toString() const {
    return "Kraken";
}
