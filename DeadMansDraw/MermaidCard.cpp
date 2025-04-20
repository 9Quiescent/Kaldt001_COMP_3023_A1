#include "MermaidCard.h"

MermaidCard::MermaidCard(int pointValue)
    : Card(Suit::Mermaid, pointValue, new MermaidCardAbility())
{
}

MermaidCard::~MermaidCard()
{
    
}

std::string MermaidCard::toString() const
{
    return "Mermaid";
}

void MermaidCard::play(Player& player)
{
    ability->apply(static_cast<Card&>(*this), player);
}
