#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "Block.h"
#include "Board.h"

namespace FEITENG
{
    using BlockFactory = std::function<std::unique_ptr<Block>()>;

    class MapParser
    {
    public:
        static Board parseFromFile(const std::string&);

    private:
        static const std::unordered_map<std::uint8_t, BlockFactory> block_factory_map;

        static std::string blockTypeToString(Block::BlockType);
    };
} // namespace FEITENG
