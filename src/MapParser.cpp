#include "MapParser.h"

#include <fstream>
#include <sstream>
#include <map>

namespace FEITENG
{
    std::unordered_map<std::uint8_t, MapParser::BlockFactory> MapParser::BLOCK_FACTORY_MAP = {};

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
        Board::Grid grid;
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

                auto it = BLOCK_FACTORY_MAP.find(byte);
                if(it != BLOCK_FACTORY_MAP.end())
                {
                    grid[i][j] = it->second(file);
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
        std::string statistics = oss.str() + '\n';
        statistics += "Minimum Path: " + std::to_string(min_path) + "\n\n";

        return Board(width, height, std::move(name), std::move(statistics), std::move(grid));
    }
} // namespace FEITENG
