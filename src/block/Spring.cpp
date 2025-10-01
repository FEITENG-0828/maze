#include "Spring.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Spring::REGISTERED = MapParser::registerBlock<Spring>(Spring::ID);

    Spring::Spring(Direction dir, int dist): direction(dir), distance(dist)
    {
        block_type = BlockType::SPRING;
    }

    std::string Spring::getName() const
    {
        return "Spring";
    }

    std::string Spring::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = direction;
        switch(direction)
        {
            case Direction::UP:
                displacement += { distance, 0 };
                break;
            case Direction::DOWN:
                displacement += { -distance, 0 };
                break;
            case Direction::LEFT:
                displacement += { 0, -distance };
                break;
            case Direction::RIGHT:
                displacement += { 0, distance };
                break;
        }
        return "Spring";
    }

    void Spring::load(std::istream& is)
    {
        std::uint8_t dir;
        is.read(reinterpret_cast<char*>(&dir), sizeof(dir));
        switch(dir)
        {
            case 0x00:
                direction = Direction::UP;
                break;
            case 0x01:
                direction = Direction::DOWN;
                break;
            case 0x02:
                direction = Direction::LEFT;
                break;
            case 0x03:
                direction = Direction::RIGHT;
                break;
        }

        is.read(reinterpret_cast<char*>(&distance), sizeof(distance));
    }

    void Spring::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));

        std::uint8_t dir;
        switch(direction)
        {
            case Direction::UP:
                dir = 0x00;
                break;
            case Direction::DOWN:
                dir = 0x01;
                break;
            case Direction::LEFT:
                dir = 0x02;
                break;
            case Direction::RIGHT:
                dir = 0x03;
                break;
        }
        os.write(reinterpret_cast<const char*>(&dir), sizeof(dir));

        os.write(reinterpret_cast<const char*>(&distance), sizeof(distance));
    }
} // namespace FEITENG
