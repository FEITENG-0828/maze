#include "Teleport.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Teleport::REGISTERED = MapParser::registerBlock<Teleport>(Teleport::ID);

    Teleport::Teleport(Pos r_p): relative_pos(r_p)
    {
        block_type = BlockType::TELEPORT;
    }

    std::string Teleport::getName() const
    {
        return "Teleport";
    }

    std::string Teleport::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
        displacement += relative_pos;
        return "Teleport";
    }

    void Teleport::load(std::istream& is)
    {
        is.read(reinterpret_cast<char*>(&relative_pos.x), sizeof(relative_pos.x));
        is.read(reinterpret_cast<char*>(&relative_pos.y), sizeof(relative_pos.y));
    }

    void Teleport::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));

        os.write(reinterpret_cast<const char*>(&relative_pos.x), sizeof(relative_pos.x));
        os.write(reinterpret_cast<const char*>(&relative_pos.y), sizeof(relative_pos.y));
    }
} // namespace FEITENG
