#include "KrakenCard.h"

KrakenCard::KrakenCard(int pointValue)
    : Card(Suit::Kraken, pointValue, new KrakenCardAbility())
{
}

KrakenCard::~KrakenCard()
{
    
}

std::string KrakenCard::toString() const
{
    return "Kraken";
}

void KrakenCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
