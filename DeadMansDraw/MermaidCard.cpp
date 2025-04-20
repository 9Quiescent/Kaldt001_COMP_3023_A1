#include "MermaidCard.h"

MermaidCard::MermaidCard()
    : Card(Suit::Mermaid, 9, new MermaidCardAbility())
{
}

std::string MermaidCard::toString() const
{
    return "Mermaid";
}
