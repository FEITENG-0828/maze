#pragma once

#include "Block.h"

namespace FEITENG
{
    class Border : public Block
    {
    public:
        Border();
        virtual ~Border() = default;

        virtual std::string getName() const override;
        virtual void scheduleMove(Player::Heading&, Pos&) override;
        virtual std::string getDescription() const override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    private:
        static constexpr std::uint8_t ID = 0x10;
        static bool REGISTERED;
    };
} // namespace FEITENG
