#pragma once

#include "Block.h"

namespace FEITENG
{
    class Empty : public Block
    {
    public:
        enum class EmptyType
        {
            NORMAL,
            START,
            END
        };

        Empty();
        virtual ~Empty() = default;

        virtual std::string getName() const override;
        virtual void scheduleMove(Player::Heading&, Pos&) override;
        virtual std::string getDescription() const override;

    protected:
        EmptyType empty_type;
    };
} // namespace FEITENG
