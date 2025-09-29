#pragma once

#include <vector>
#include <memory>

#include "Block.h"

namespace FEITENG
{
    using Grid = std::vector<std::vector<std::unique_ptr<Block>>>;

    class Board
    {
    public:
        Board();
        ~Board() = default;

        int getWidth() const;
        int getHeight() const;
        std::string getName() const;

        void step(Player&, Pos&, std::string&);

    private:
        int width;
        int height;
        std::string name;

        Grid grid;
    };
} // namespace FEITENG
