#include "Empty.h"

namespace FEITENG
{
    Empty::Empty()
    {
        block_type = BlockType::EMPTY;
        empty_type = EmptyType::NORMAL;
    }

    std::string Empty::getName() const
    {
        return "Empty";
    }

    void Empty::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
    }

    std::string Empty::getDescription() const
    {
        return "Empty";
    }
} // namespace FEITENG
