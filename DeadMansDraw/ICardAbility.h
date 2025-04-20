#pragma once

class Player;
class Game;

class ICardAbility
{
public:
    virtual ~ICardAbility() = default;
    virtual void apply(Game& game, Player& player) = 0;
};
