#include "Start.h"

namespace FEITENG
{
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
} // namespace FEITENG
