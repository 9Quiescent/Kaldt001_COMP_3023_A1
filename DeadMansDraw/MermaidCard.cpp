#include "MermaidCard.h"

MermaidCard::MermaidCard(int pointValue)
    : Card(Suit::Mermaid, pointValue, new MermaidCardAbility())
{
}

std::string MermaidCard::toString() const {
    return "Mermaid";
}
