#include "End.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool End::REGISTERED = MapParser::registerBlock<End>(End::ID);

    End::End()
    {
        empty_type = EmptyType::END;
    }

    std::string End::getName() const
    {
        return "End";
    }

    std::string End::getDescription() const
    {
        return "End";
    }

    void End::load(std::istream&)
    { }

    void End::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));
    }
} // namespace FEITENG
