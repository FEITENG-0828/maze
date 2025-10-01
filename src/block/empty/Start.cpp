#include "Start.h"

#include <istream>
#include <ostream>

#include "MapParser.h"

namespace FEITENG
{
    bool Start::REGISTERED = MapParser::registerBlock<Start>(Start::ID);

    Start::Start()
    {
        empty_type = EmptyType::START;
    }

    std::string Start::getName() const
    {
        return "Start";
    }

    std::string Start::getDescription() const
    {
        return "Start";
    }

    void Start::load(std::istream&)
    { }

    void Start::save(std::ostream& os) const
    {
        os.write(reinterpret_cast<const char*>(&ID), sizeof(ID));
    }
} // namespace FEITENG
