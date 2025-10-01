#pragma once

#include "Empty.h"

namespace FEITENG
{
    class Start : public Empty
    {
    public:
        Start();
        virtual ~Start() = default;

        virtual std::string getName() const override;
        virtual std::string scheduleMove(Player::Heading&, Pos&) override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    private:
        static constexpr std::uint8_t ID = 0x21;
        static bool REGISTERED;
    };
} // namespace FEITENG
