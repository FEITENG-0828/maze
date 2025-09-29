#pragma once

namespace FEITENG
{
    struct Pos
    {
        int x, y;

        Pos operator+(const Pos& other) const;
        Pos& operator+=(const Pos& other);
        Pos operator-(const Pos& other) const;
        Pos& operator-=(const Pos& other);
        Pos& toZero();
    };
} // namespace FEITENG