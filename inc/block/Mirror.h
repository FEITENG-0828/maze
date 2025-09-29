#pragma once

#include "Block.h"

namespace FEITENG
{
    class Mirror : public Block
    {
    public:
        enum class MirrorType
        {
            LEFT,  // '\'
            RIGHT  // '/'
        };

        Mirror(MirrorType);
        virtual ~Mirror() = default;

        virtual std::string getName() const override;
        virtual void scheduleMove(Player::Heading&, Pos&) override;
        virtual std::string getDescription() const override;

        protected:
            MirrorType mirror_type;
    };
} // namespace FEITENG
