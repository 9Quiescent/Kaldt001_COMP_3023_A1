#include "KrakenCard.h"

KrakenCard::KrakenCard(int pointValue)
    : Card(Suit::Kraken, pointValue, CardType::Kraken, new KrakenCardAbility())
{
}

KrakenCard::~KrakenCard()
{
}

void KrakenCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
