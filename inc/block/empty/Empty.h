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

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    protected:
        EmptyType empty_type;

    private:
        static constexpr std::uint8_t ID = 0x20;
        static bool REGISTERED;
    };
} // namespace FEITENG
