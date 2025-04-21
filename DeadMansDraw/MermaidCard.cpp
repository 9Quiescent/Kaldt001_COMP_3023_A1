#include "MermaidCard.h"

MermaidCard::MermaidCard(int pointValue)
    : Card(Suit::Mermaid, pointValue, CardType::Mermaid, new MermaidCardAbility())
{
}

MermaidCard::~MermaidCard()
{
}

void MermaidCard::play(Player& player, Game& game)
{
    if (ability)
        ability->apply(*this, player);
}
