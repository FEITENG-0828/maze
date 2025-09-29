#include "Board.h"

#include "Border.h"
#include "Start.h"
#include "End.h"
#include "Empty.h"
#include "Mirror.h"
#include "Wall.h"
#include "Player.h"

namespace FEITENG
{
    Board::Board(): // FIXME: hard-coded
        width(4 + 2),
        height(4 + 2),
        name(u8"测试")
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
                else if(i == 1 && j == 2)
                {
                    grid[i][j] = std::make_unique<Mirror>(Mirror::MirrorType::LEFT);
                }
                else if(i == 4 && j == 2)
                {
                    grid[i][j] = std::make_unique<Mirror>(Mirror::MirrorType::RIGHT);
                }
                else if((i == 1 && j == 3) || (i == 4 && j == 3))
                {
                    grid[i][j] = std::make_unique<Wall>();
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

    void Board::step(Player& player, Pos& displacement, std::string& hint)
    {
        auto& block = grid[(player.pos + displacement).x][(player.pos + displacement).y];
        block->scheduleMove(player.heading, displacement);
        hint += block->getDescription() + ' ';
    }
} // namespace FEITENG
