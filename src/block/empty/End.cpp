#include "End.h"

namespace FEITENG
{
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
} // namespace FEITENG
