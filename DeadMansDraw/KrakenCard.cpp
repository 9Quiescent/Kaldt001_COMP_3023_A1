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

void KrakenCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
