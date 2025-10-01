#pragma once

#include "Block.h"

namespace FEITENG
{
    class Mirror: public Block
    {
    public:
        enum class MirrorType
        {
            LEFT, // '\'
            RIGHT // '/'
        };

        Mirror(MirrorType = MirrorType::LEFT);
        virtual ~Mirror() = default;

        virtual std::string getName() const override;
        virtual void scheduleMove(Player::Heading&, Pos&) override;
        virtual std::string getDescription() const override;

        virtual void load(std::istream&) override;
        virtual void save(std::ostream&) const override;

    protected:
        MirrorType mirror_type;

    private:
        static constexpr std::uint8_t ID = 0x40;
        static bool REGISTERED;
    };
} // namespace FEITENG
