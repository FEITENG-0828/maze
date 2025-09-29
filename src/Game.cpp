#include <sstream>

#include "Game.h"

namespace FEITENG
{
    Game::Game(): pos(Pos{ 1, 1 })
    { }

    std::string Game::getBoardInfo() const
    {
        std::ostringstream oss;
        oss << "Board Name: " << board.getName() << '\n';
        oss << "Dimensions: " << board.getWidth() - 2 << " * " << board.getHeight() - 2 << '\n';
        oss << "Statistics:\n"; // TODO: count different types of blocks

        return oss.str();
    }

    void Game::move(const Pos& direction)
    {
        hint.clear();

        Pos displacement = direction;
        bool need_transition = true;
        while(need_transition)
        {
            need_transition = board.step(pos, displacement, hint);
        }
        pos += displacement;
    }

    std::string Game::getHint() const
    {
        return hint;
    }
} // namespace FEITENG
