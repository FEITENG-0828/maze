#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void writeMapToFile(const std::string& file_name)
{
    std::ofstream file(file_name, std::ios::binary);
    if(!file)
    {
        throw std::runtime_error("Cannot open file for writing: " + file_name);
    }

    int width = 4, height = 4;
    std::string name = "测试";
    std::vector<std::vector<std::uint8_t>> grid = {
        { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 },
        { 0x10, 0x20, 0x20, 0x20, 0x22, 0x10 },
        { 0x10, 0x30, 0x50, 0x01, 0x20, 0x30, 0x10 },
        { 0x10, 0x40, 0x00, 0x20, 0x50, 0x00, 0x20, 0x10 },
        { 0x10, 0x21, 0x20, 0x20, 0x20, 0x10 },
        { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 }
    };
    int min_path = 5;

    file.write(reinterpret_cast<const char*>(&width), sizeof(int));
    file.write(reinterpret_cast<const char*>(&height), sizeof(int));

    size_t name_length = name.size();
    file.write(reinterpret_cast<const char*>(&name_length), sizeof(size_t));
    file.write(name.c_str(), name_length);

    for(int i = height + 1; i >= 0; --i)
    {
        for(auto byte: grid[i])
        {
            file.write(reinterpret_cast<const char*>(&byte), 1);
        }
    }

    file.write(reinterpret_cast<const char*>(&min_path), sizeof(int));

    std::cout << "Map written to " << file_name << "\n";
}

int main()
{
    writeMapToFile("test.maze");

    return 0;
}
