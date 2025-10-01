#pragma once

#include "Block.h"

namespace FEITENG
{
    class Teleport: public Block
    {
    public:
        Teleport(Pos = { 0, 0 });
        virtual ~Teleport() = default;

        virtual std::string getName() const override;
        virtual std::string scheduleMove(Player::Heading&, Pos&) override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    protected:
        Pos relative_pos;

    private:
        static constexpr std::uint8_t ID = 0x60;
        static bool REGISTERED;
    };
} // namespace FEITENG
