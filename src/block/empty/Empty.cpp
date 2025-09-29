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

    bool Empty::scheduleMove(Pos& displacement)
    {
        return false;
    }

    std::string Empty::getDescription() const
    {
        return "Empty";
    }
} // namespace FEITENG
