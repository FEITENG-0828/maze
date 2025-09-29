#include "Wall.h"

namespace FEITENG
{
    Wall::Wall()
    {
        block_type = BlockType::WALL;
    }

    std::string Wall::getName() const
    {
        return "Wall";
    }

    void Wall::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
        displacement.toZero();
    }

    std::string Wall::getDescription() const
    {
        return "Wall";
    }
} // namespace FEITENG
