#pragma once

#include "Board.h"

namespace FEITENG
{
    class Game
    {
    public:
        Game();
        ~Game() = default;

        std::string getBoardInfo() const;
        void move(const Pos&);
        std::string getHint() const;

    private:
        Board board;
        Pos pos;
        std::string hint;
    };
} // namespace FEITENG
