#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "Block.h"
#include "Board.h"

namespace FEITENG
{
    class MapParser
    {
    public:
        using BlockFactory = std::function<std::unique_ptr<Block>(std::istream&)>;

        template<typename BlockType>
            static bool registerBlock(std::uint8_t);

        static Board parseFromFile(const std::string&);

    private:
        static std::unordered_map<std::uint8_t, BlockFactory> BLOCK_FACTORY_MAP;

        static std::string blockTypeToString(Block::BlockType);
    };

    template<typename BlockType>
        inline bool MapParser::registerBlock(std::uint8_t id)
    {
        if(BLOCK_FACTORY_MAP.find(id) != BLOCK_FACTORY_MAP.end())
        {
            return false;
        }
        else
        {
            BLOCK_FACTORY_MAP[id] = [](std::istream& is)
            {
                auto block = std::make_unique<BlockType>();
                block->load(is);
                return block;
            };
            return true;
        }
    }
} // namespace FEITENG
