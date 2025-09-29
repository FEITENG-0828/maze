#pragma once

#include "Empty.h"

namespace FEITENG
{
    class End : public Empty
    {
    public:
        End();
        virtual ~End() = default;

        virtual std::string getName() const override;
        virtual std::string getDescription() const override;
    };
} // namespace FEITENG
