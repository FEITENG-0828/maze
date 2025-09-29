#pragma once

#include "Empty.h"

namespace FEITENG
{
    class Start : public Empty
    {
    public:
        Start();
        virtual ~Start() = default;

        virtual std::string getName() const override;
        virtual std::string getDescription() const override;
    };
} // namespace FEITENG
