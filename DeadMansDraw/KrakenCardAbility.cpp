#include "KrakenCardAbility.h"
#include "Player.h"
#include "Game.h"
#include "Card.h"
#include <iostream>

void KrakenCardAbility::apply(Card& card, Player& player) {
    Game* game = player.getGame();
    if (game == nullptr) return;

    std::cout << "Kraken Ability Activated: Must draw and play three cards consecutively!" << std::endl;

    for (int i = 0; i < 3; ++i) {
        Card* forcedCard = game->drawCard();
        if (forcedCard == nullptr) {
            std::cout << "No more cards to draw." << std::endl;
            break;
        }

        std::cout << player.getName() << " draws " << forcedCard->str() << " (Kraken forced draw)!" << std::endl;
        player.addToPlayArea(forcedCard);

        if (forcedCard->shouldPlayImmediately()) {
            forcedCard->play(player, *game);
        }

        std::cout << player.getName() << "'s Play Area after Kraken draw:" << std::endl;
        for (Card* c : player.getPlayArea()) {
            if (c != nullptr) {
                std::cout << "  " << c->str() << std::endl;
            }
        }

        if (game->handleBust(player)) {
            std::cout << "Bust occurred! Kraken ability ends immediately." << std::endl;
            break; // Stops kraken draw loop if we bust early
        }
    }
}

std::string KrakenCardAbility::toString() const {
    return "Kraken";
}
