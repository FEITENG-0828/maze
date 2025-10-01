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
        virtual std::string scheduleMove(Player::Heading&, Pos&) override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    private:
        static constexpr std::uint8_t ID = 0x30;
        static bool REGISTERED;
    };
} // namespace FEITENG