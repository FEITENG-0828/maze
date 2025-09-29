#pragma once

#include "Board.h"
#include "Player.h"

namespace FEITENG
{
    class Game
    {
    public:
        Game() = default;
        ~Game() = default;

        std::string getBoardInfo() const;
        std::string move(Player::Heading);
        std::string getHint() const;

    private:
        Board board;
        Player player;
    };
} // namespace FEITENG
