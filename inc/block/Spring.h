#pragma once

#include "Block.h"

namespace FEITENG
{
    class Spring: public Block
    {
    public:
        using Direction = Player::Heading;

        Spring(Direction = Direction::UP, int = 0);
        virtual ~Spring() = default;

        virtual std::string getName() const override;
        virtual std::string scheduleMove(Player::Heading&, Pos&) override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    protected:
        Direction direction;
        int distance;

    private:
        static constexpr std::uint8_t ID = 0x70;
        static bool REGISTERED;
    };
} // namespace FEITENG
