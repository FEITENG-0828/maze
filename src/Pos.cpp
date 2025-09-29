#include "Pos.h"

namespace FEITENG
{
    Pos Pos::operator+(const Pos& other) const
    {
        return Pos{x + other.x, y + other.y};
    }

    Pos& Pos::operator+=(const Pos& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Pos Pos::operator-(const Pos& other) const
    {
        return Pos{x - other.x, y - other.y};
    }

    Pos& Pos::operator-=(const Pos& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Pos& Pos::toZero()
    {
        x = 0;
        y = 0;
        return *this;
    }
} // namespace FEITENG