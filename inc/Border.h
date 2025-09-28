#pragma once

#include <string>

#include "Block.h"

namespace FEITENG
{
    class Border : public Block
    {
    public:
        Border() = default;
        virtual ~Border() = default;

        virtual std::string getDescription() const override
        {
            return "Border";
        }
    };
} // namespace FEITENG
