#include "Board.h"
#include "Border.h"
#include "End.h"
#include "Start.h"

namespace FEITENG
{
    Board::Board(): // FIXME: hard-coded
        width(6 + 2),
        height(6 + 2),
        name(u8"永夜回廊")
    {
        grid.resize(height);
        for(auto& row: grid)
        {
            row.resize(width);
        }

        for(int i = 0; i < height; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
                {
                    grid[i][j] = std::make_unique<Border>();
                }
                else if(i == 1 && j == 1)
                {
                    grid[i][j] = std::make_unique<Start>();
                }
                else if(i == height - 2 && j == width - 2)
                {
                    grid[i][j] = std::make_unique<End>();
                }
                else
                {
                    grid[i][j] = std::make_unique<Empty>();
                }
            }
        }
    }

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

    bool Board::step(const Pos& pos, Pos& displacement, std::string& hint)
    {
        auto& block = grid[(pos + displacement).x][(pos + displacement).y];
        hint += block->getDescription() + ' ';
        return block->scheduleMove(displacement);
    }
} // namespace FEITENG
