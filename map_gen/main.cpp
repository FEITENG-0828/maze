#include <fstream>
#include <iostream>
#include <string>

#include "Board.h"
#include "Border.h"
#include "Empty.h"
#include "Start.h"
#include "End.h"
#include "Wall.h"
#include "Mirror.h"
#include "Polarizer.h"
#include "Teleport.h"
#include "Spring.h"

void writeMapToFile(const std::string& file_name)
{
    using namespace FEITENG;

    std::ofstream file(file_name, std::ios::binary);
    if(!file)
    {
        throw std::runtime_error("Cannot open file for writing: " + file_name);
    }

    int width = 6, height = 6;
    std::string name = "永夜回廊";

    Board::Grid grid;
    grid.resize(height + 2);
    for(auto& row: grid)
    {
        row.resize(width + 2);
    }

    grid[0][0] = std::make_unique<Border>();
    grid[0][1] = std::make_unique<Border>();
    grid[0][2] = std::make_unique<Border>();
    grid[0][3] = std::make_unique<Border>();
    grid[0][4] = std::make_unique<Border>();
    grid[0][5] = std::make_unique<Border>();
    grid[0][6] = std::make_unique<Border>();
    grid[0][7] = std::make_unique<Border>();

    grid[1][0] = std::make_unique<Border>();
    grid[1][1] = std::make_unique<Start>();
    grid[1][2] = std::make_unique<Empty>();
    grid[1][3] = std::make_unique<Polarizer>(Polarizer::PolarizerType::HORIZONTAL);
    grid[1][4] = std::make_unique<Teleport>(Pos{ 5, 0 });
    grid[1][5] = std::make_unique<Mirror>(Mirror::MirrorType::LEFT);
    grid[1][6] = std::make_unique<Spring>(Spring::Direction::LEFT, 4);
    grid[1][7] = std::make_unique<Border>();

    grid[2][0] = std::make_unique<Border>();
    grid[2][1] = std::make_unique<Empty>();
    grid[2][2] = std::make_unique<Mirror>(Mirror::MirrorType::RIGHT);
    grid[2][3] = std::make_unique<Empty>();
    grid[2][4] = std::make_unique<Mirror>(Mirror::MirrorType::RIGHT);
    grid[2][5] = std::make_unique<Empty>();
    grid[2][6] = std::make_unique<Mirror>(Mirror::MirrorType::RIGHT);
    grid[2][7] = std::make_unique<Border>();

    grid[3][0] = std::make_unique<Border>();
    grid[3][1] = std::make_unique<Polarizer>(Polarizer::PolarizerType::HORIZONTAL);
    grid[3][2] = std::make_unique<Spring>(Spring::Direction::RIGHT, 4);
    grid[3][3] = std::make_unique<Polarizer>(Polarizer::PolarizerType::HORIZONTAL);
    grid[3][4] = std::make_unique<Empty>();
    grid[3][5] = std::make_unique<Polarizer>(Polarizer::PolarizerType::HORIZONTAL);
    grid[3][6] = std::make_unique<Empty>();
    grid[3][7] = std::make_unique<Border>();

    grid[4][0] = std::make_unique<Border>();
    grid[4][1] = std::make_unique<Spring>(Spring::Direction::RIGHT, 3);
    grid[4][2] = std::make_unique<Polarizer>(Polarizer::PolarizerType::VERTICAL);
    grid[4][3] = std::make_unique<Teleport>(Pos{ 1, 0 });
    grid[4][4] = std::make_unique<Empty>();
    grid[4][5] = std::make_unique<Wall>();
    grid[4][6] = std::make_unique<Spring>(Spring::Direction::LEFT, 2);
    grid[4][7] = std::make_unique<Border>();

    grid[5][0] = std::make_unique<Border>();
    grid[5][1] = std::make_unique<Polarizer>(Polarizer::PolarizerType::HORIZONTAL);
    grid[5][2] = std::make_unique<Empty>();
    grid[5][3] = std::make_unique<Teleport>(Pos{ -1, 0 });
    grid[5][4] = std::make_unique<Mirror>(Mirror::MirrorType::LEFT);
    grid[5][5] = std::make_unique<Empty>();
    grid[5][6] = std::make_unique<Mirror>(Mirror::MirrorType::RIGHT);
    grid[5][7] = std::make_unique<Border>();

    grid[6][0] = std::make_unique<Border>();
    grid[6][1] = std::make_unique<Empty>();
    grid[6][2] = std::make_unique<Polarizer>(Polarizer::PolarizerType::HORIZONTAL);
    grid[6][3] = std::make_unique<Mirror>(Mirror::MirrorType::LEFT);
    grid[6][4] = std::make_unique<Teleport>(Pos{ -5, 0 });
    grid[6][5] = std::make_unique<Spring>(Spring::Direction::LEFT, 4);
    grid[6][6] = std::make_unique<End>();
    grid[6][7] = std::make_unique<Border>();

    grid[7][0] = std::make_unique<Border>();
    grid[7][1] = std::make_unique<Border>();
    grid[7][2] = std::make_unique<Border>();
    grid[7][3] = std::make_unique<Border>();
    grid[7][4] = std::make_unique<Border>();
    grid[7][5] = std::make_unique<Border>();
    grid[7][6] = std::make_unique<Border>();
    grid[7][7] = std::make_unique<Border>();

    int min_path = 6;

    file.write(reinterpret_cast<const char*>(&width), sizeof(int));
    file.write(reinterpret_cast<const char*>(&height), sizeof(int));

    size_t name_length = name.size();
    file.write(reinterpret_cast<const char*>(&name_length), sizeof(size_t));
    file.write(name.c_str(), name_length);

    for(const auto& row: grid)
    {
        for(const auto& block_ptr: row)
        {
            block_ptr->save(file);
        }
    }

    file.write(reinterpret_cast<const char*>(&min_path), sizeof(int));

    std::cout << "Map written to " << file_name << "\n";
}

int main()
{
    writeMapToFile("map.maze");

    return 0;
}
