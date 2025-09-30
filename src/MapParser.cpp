#include "MapParser.h"

#include <fstream>
#include <sstream>
#include <map>

#include "Border.h"
#include "Empty.h"
#include "End.h"
#include "Mirror.h"
#include "Start.h"
#include "Wall.h"

namespace FEITENG
{
    const std::unordered_map<std::uint8_t, BlockFactory> MapParser::block_factory_map = {
        { 0x10, []() { return std::make_unique<Border>(); } },
        { 0x20, []() { return std::make_unique<Empty>(); } },
        { 0x21, []() { return std::make_unique<Start>(); } },
        { 0x22, []() { return std::make_unique<End>(); } },
        { 0x30, []() { return std::make_unique<Wall>(); } },
        { 0x40, []() { return std::make_unique<Mirror>(Mirror::MirrorType::LEFT); } },
        { 0x41, []() { return std::make_unique<Mirror>(Mirror::MirrorType::RIGHT); } }
    };

    std::string MapParser::blockTypeToString(Block::BlockType type)
    {
        switch(type)
        {
            case Block::BlockType::WALL:
                return "Wall";
            case Block::BlockType::MIRROR:
                return "Mirror";
            case Block::BlockType::POLARIZER:
                return "Polarizer";
            case Block::BlockType::TELEPORT:
                return "Teleport";
            case Block::BlockType::SPRING:
                return "Spring";
            default:
                return "";
        }
    }

    Board MapParser::parseFromFile(const std::string& file_name)
    {
        std::ifstream file(file_name, std::ios::binary);
        if(!file)
        {
            throw std::runtime_error("Cannot open file: " + file_name);
        }

        int width = 0, height = 0;
        file.read(reinterpret_cast<char*>(&width), sizeof(int));
        if(file.fail())
        {
            throw std::runtime_error("Failed to read width");
        }
        file.read(reinterpret_cast<char*>(&height), sizeof(int));
        if(file.fail())
        {
            throw std::runtime_error("Failed to read height");
        }

        size_t name_length = 0;
        file.read(reinterpret_cast<char*>(&name_length), sizeof(size_t));
        if(file.fail())
        {
            throw std::runtime_error("Failed to read name_length");
        }

        std::string name(name_length, '\0');
        if(name_length > 0)
        {
            file.read(name.data(), name_length);
            if(file.fail())
            {
                throw std::runtime_error("Failed to read name");
            }
        }

        int rows = width + 2, columns = height + 2;
        Grid grid;
        std::map<std::string, int> block_type_cnt;

        grid.resize(rows);
        for(auto& row: grid)
        {
            row.resize(columns);
        }

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < columns; ++j)
            {
                std::uint8_t byte = 0x00;
                file.read(reinterpret_cast<char*>(&byte), 1);
                if(file.fail())
                {
                    throw std::runtime_error("Failed to read grid byte at ("
                        + std::to_string(i) + "," + std::to_string(j) + ")");
                }

                auto it = block_factory_map.find(byte);
                if(it != block_factory_map.end())
                {
                    grid[i][j] = it->second();
                }
                else
                {
                    throw std::runtime_error("Unknown block type byte: "
                        + std::to_string(static_cast<int>(byte)) + " at ("
                        + std::to_string(i) + "," + std::to_string(j) + ")");
                }

                std::string type_str = blockTypeToString(grid[i][j]->getBlockType());
                if(!type_str.empty())
                {
                    ++block_type_cnt[type_str];
                }
            }
        }

        int min_path = 0;
        file.read(reinterpret_cast<char*>(&min_path), sizeof(int));
        if(file.fail())
        {
            throw std::runtime_error("Failed to read min_path");
        }

        std::ostringstream oss;
        for(const auto& [type, count]: block_type_cnt)
        {
            oss << type << ": " << count << '\n';
        }
        std::string statistics = oss.str() + "Min Path: " + std::to_string(min_path) + '\n';

        return Board(width, height, std::move(name), std::move(statistics), std::move(grid));
    }
} // namespace FEITENG
