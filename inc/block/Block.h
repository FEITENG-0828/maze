#pragma once

#include <string>

#include "Player.h"
#include "Pos.h"

namespace FEITENG
{
    class Block
    {
    public:
        enum class BlockType
        {
            NONE,
            BORDER,
            EMPTY,
            WALL,
            MIRROR,
            POLARIZER,
            TELEPORT,
            SPRING
        };

        Block(): block_type(BlockType::NONE) {};
        virtual ~Block() = default;

        virtual std::string getName() const = 0;
        virtual std::string scheduleMove(Player::Heading&, Pos&) = 0;

        BlockType getBlockType() const
        {
            return block_type;
        }
        virtual void load(std::istream&) = 0;
        virtual void save(std::ostream&) const = 0;

    protected:
        BlockType block_type;
    };
} // namespace FEITENG
