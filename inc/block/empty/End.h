#pragma once

#include "Empty.h"

namespace FEITENG
{
    class End : public Empty
    {
    public:
        End();
        virtual ~End() = default;

        virtual std::string getName() const override;
        virtual std::string scheduleMove(Player::Heading&, Pos&) override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    private:
        static constexpr std::uint8_t ID = 0x22;
        static bool REGISTERED;
    };
} // namespace FEITENG
