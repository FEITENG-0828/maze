#pragma once

#include "Block.h"

namespace FEITENG
{
    class Wall : public Block
    {
    public:
        Wall();
        virtual ~Wall() = default;

        virtual std::string getName() const override;
        virtual void scheduleMove(Player::Heading&, Pos&) override;
        virtual std::string getDescription() const override;
    };
} // namespace FEITENG