#include "Border.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Border::REGISTERED = MapParser::registerBlock<Border>(Border::ID);

    Border::Border()
    {
        block_type = BlockType::BORDER;
    }

    std::string Border::getName() const
    {
        return "Border";
    }

    void Border::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        heading = Player::Heading::NONE;
        displacement.toZero();
    }

    std::string Border::getDescription() const
    {
        return "Border";
    }

    void Border::load(std::istream&)
    { }

    void Border::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));
    }
} // namespace FEITENG
