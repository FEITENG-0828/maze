#include "Border.h"

namespace FEITENG
{
    Border::Border()
    {
        block_type = BlockType::BORDER;
    }

    std::string Border::getName() const
    {
        return "Border";
    }

    void Border::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
        displacement.toZero();
    }

    std::string Border::getDescription() const
    {
        return "Border";
    }
} // namespace FEITENG
