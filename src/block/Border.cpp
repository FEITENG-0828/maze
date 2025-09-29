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

    bool Border::scheduleMove(Pos& displacement)
    {
        displacement.toZero();
        return false;
    }

    std::string Border::getDescription() const
    {
        return "Border";
    }
} // namespace FEITENG
