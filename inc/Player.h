#pragma once

#include "Pos.h"

namespace FEITENG
{
    struct Player
    {
        enum class Heading
        {
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        Pos pos;
        Heading heading;

        Player(): pos{ 1, 1 }, heading(Heading::NONE)
        { }
    };
} // namespace FEITENG
