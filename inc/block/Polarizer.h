#pragma once

#include "Block.h"

namespace FEITENG
{
    class Polarizer: public Block
    {
    public:
        enum class PolarizerType
        {
            HORIZONTAL, // '-'
            VERTICAL    // '|'
        };

        Polarizer(PolarizerType type = PolarizerType::HORIZONTAL);
        ~Polarizer() = default;

        virtual std::string getName() const override;
        virtual std::string scheduleMove(Player::Heading&, Pos&) override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    protected:
        PolarizerType polarizer_type;

    private:
        static constexpr std::uint8_t ID = 0x50;
        static bool REGISTERED;
    };
} // namespace FEITENG
