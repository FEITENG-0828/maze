#pragma once

#include <string>

#include "Block.h"

namespace FEITENG
{
    class Border : public Block
    {
    public:
        Border();
        virtual ~Border() = default;

        virtual std::string getName() const override;
        virtual bool scheduleMove(Pos&) override;
        virtual std::string getDescription() const override;
    };
} // namespace FEITENG
