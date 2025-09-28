#pragma once

#include <string>

namespace FEITENG
{
    class Block
    {
    public:
        Block() = default;
        virtual ~Block() = default;

        virtual std::string getDescription() const
        {
            return "Block";
        }
    };
} // namespace FEITENG
