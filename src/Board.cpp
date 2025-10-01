#include "Board.h"

namespace FEITENG
{
    Board::Board(int w, int h, std::string&& n, std::string&& s, Grid&& g):
        width(w + 2),
        height(h + 2),
        name(std::move(n)),
        statistics(std::move(s)),
        grid(std::move(g))
    { }

    int Board::getWidth() const
    {
        return width;
    }

    int Board::getHeight() const
    {
        return height;
    }

    std::string Board::getName() const
    {
        return name;
    }

    std::string Board::getStatistics() const
    {
        return statistics;
    }

    void Board::step(Player& player, Pos& displacement, std::string& hint)
    {
        auto& block = grid[(player.pos + displacement).x][(player.pos + displacement).y];
        std::string new_hint = block->scheduleMove(player.heading, displacement);
        if(!new_hint.empty())
        {
            hint += new_hint + ' ';
        }
    }
} // namespace FEITENG
