#pragma once

#include "Board.h"
#include "Player.h"

namespace FEITENG
{
    class Game
    {
    public:
        Game(const std::string&);
        ~Game() = default;

        std::string getBoardInfo() const;
        std::string move(Player::Heading);

    private:
        Board board;
        Player player;
    };
} // namespace FEITENG
