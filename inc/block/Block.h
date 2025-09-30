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

        BlockType getBlockType() const { return block_type; }
        virtual std::string getName() const = 0;
        virtual void scheduleMove(Player::Heading&, Pos&) = 0;
        virtual std::string getDescription() const = 0;

    protected:
        BlockType block_type;
    };
} // namespace FEITENG
