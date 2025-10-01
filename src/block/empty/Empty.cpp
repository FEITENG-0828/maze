#include "Empty.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Empty::REGISTERED = MapParser::registerBlock<Empty>(Empty::ID);

    Empty::Empty()
    {
        block_type = BlockType::EMPTY;
        empty_type = EmptyType::NORMAL;
    }

    std::string Empty::getName() const
    {
        return "Empty";
    }

    std::string Empty::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
        return "Empty";
    }

    void Empty::load(std::istream&)
    { }

    void Empty::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));
    }
} // namespace FEITENG
