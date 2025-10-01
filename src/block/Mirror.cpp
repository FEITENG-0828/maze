#include "Mirror.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Mirror::REGISTERED = MapParser::registerBlock<Mirror>(Mirror::ID);

    Mirror::Mirror(MirrorType type): mirror_type(type)
    {
        block_type = BlockType::MIRROR;
    }

    std::string Mirror::getName() const
    {
        return "Mirror";
    }

    std::string Mirror::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        switch(mirror_type)
        {
            case MirrorType::LEFT: // '\'
                switch(heading)
                {
                    case Player::Heading::UP:
                        heading = Player::Heading::LEFT;
                        displacement += { 0, -1 };
                        break;
                    case Player::Heading::DOWN:
                        heading = Player::Heading::RIGHT;
                        displacement += { 0, 1 };
                        break;
                    case Player::Heading::LEFT:
                        heading = Player::Heading::UP;
                        displacement += { 1, 0 };
                        break;
                    case Player::Heading::RIGHT:
                        heading = Player::Heading::DOWN;
                        displacement += { -1, 0 };
                        break;
                }
                break;
            case MirrorType::RIGHT: // '/'
                switch(heading)
                {
                    case Player::Heading::UP:
                        heading = Player::Heading::RIGHT;
                        displacement += { 0, 1 };
                        break;
                    case Player::Heading::DOWN:
                        heading = Player::Heading::LEFT;
                        displacement += { 0, -1 };
                        break;
                    case Player::Heading::LEFT:
                        heading = Player::Heading::DOWN;
                        displacement += { -1, 0 };
                        break;
                    case Player::Heading::RIGHT:
                        heading = Player::Heading::UP;
                        displacement += { 1, 0 };
                        break;
                }
                break;
        }
        return "Mirror";
    }

    void Mirror::load(std::istream& is)
    {
        std::uint8_t mirror_type_byte = 0x00;
        is.read(reinterpret_cast<char*>(&mirror_type_byte), sizeof(mirror_type_byte));
        switch(mirror_type_byte)
        {
            case 0x00:
                mirror_type = MirrorType::LEFT;
                break;
            case 0x01:
                mirror_type = MirrorType::RIGHT;
                break;
        }
    }

    void Mirror::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));

        std::uint8_t mirror_type_byte;
        switch(mirror_type)
        {
            case MirrorType::LEFT:
                mirror_type_byte = 0x00;
                break;
            case MirrorType::RIGHT:
                mirror_type_byte = 0x01;
                break;
        }
        os.write(reinterpret_cast<const char*>(&mirror_type_byte), sizeof(mirror_type_byte));
    }
} // namespace FEITENG
