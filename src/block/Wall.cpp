#include "Wall.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Wall::REGISTERED = MapParser::registerBlock<Wall>(Wall::ID);

    Wall::Wall()
    {
        block_type = BlockType::WALL;
    }

    std::string Wall::getName() const
    {
        return "Wall";
    }

    void Wall::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
        displacement.toZero();
    }

    std::string Wall::getDescription() const
    {
        return "Wall";
    }

    void Wall::load(std::istream&)
    { }

    void Wall::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));
    }
} // namespace FEITENG
