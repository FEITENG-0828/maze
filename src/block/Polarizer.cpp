#include "Polarizer.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Polarizer::REGISTERED = MapParser::registerBlock<Polarizer>(Polarizer::ID);

    Polarizer::Polarizer(PolarizerType type): polarizer_type(type)
    {
        block_type = BlockType::POLARIZER;
    }

    std::string Polarizer::getName() const
    {
        return "Polarizer";
    }

    std::string Polarizer::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        std::string hint;
        switch(polarizer_type)
        {
            case PolarizerType::HORIZONTAL: // '-'
                switch(heading)
                {
                    case Player::Heading::UP:
                        displacement += { 1, 0 };
                        // hint = "Pass";
                        break;
                    case Player::Heading::DOWN:
                        displacement += { -1, 0 };
                        // hint = "Pass";
                        break;
                    case Player::Heading::LEFT:
                    case Player::Heading::RIGHT:
                        heading = Player::Heading::NONE;
                        displacement.toZero();
                        hint = "Wall";
                        break;
                }
                break;
            case PolarizerType::VERTICAL: // '|'
                switch(heading)
                {
                    case Player::Heading::UP:
                    case Player::Heading::DOWN:
                        heading = Player::Heading::NONE;
                        displacement.toZero();
                        hint = "Wall";
                        break;
                    case Player::Heading::LEFT:
                        displacement += { 0, -1 };
                        // hint = "Pass";
                        break;
                    case Player::Heading::RIGHT:
                        displacement += { 0, 1 };
                        // hint = "Pass";
                        break;
                }
                break;
        }
        return hint;
    }

    void Polarizer::load(std::istream& is)
    {
        std::uint8_t polarizer_type_byte = 0x00;
        is.read(reinterpret_cast<char*>(&polarizer_type_byte), sizeof(polarizer_type_byte));
        switch(polarizer_type_byte)
        {
            case 0x00:
                polarizer_type = PolarizerType::HORIZONTAL;
                break;
            case 0x01:
                polarizer_type = PolarizerType::VERTICAL;
                break;
        }
    }

    void Polarizer::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));

        std::uint8_t polarizer_type_byte;
        switch(polarizer_type)
        {
            case PolarizerType::HORIZONTAL:
                polarizer_type_byte = 0x00;
                break;
            case PolarizerType::VERTICAL:
                polarizer_type_byte = 0x01;
                break;
        }
        os.write(reinterpret_cast<const char*>(&polarizer_type_byte), sizeof(polarizer_type_byte));
    }
} // namespace FEITENG
