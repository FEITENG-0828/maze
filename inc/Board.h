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
        Board(int, int, std::string&&, std::string&&, Grid&&);
        Board(const Board&) = delete;
        Board(Board&&) = default;
        ~Board() = default;
        Board& operator=(const Board&) = delete;

        int getWidth() const;
        int getHeight() const;
        std::string getName() const;
        std::string getStatistics() const;

        void step(Player&, Pos&, std::string&);

    private:
        int width;
        int height;
        std::string name;
        std::string statistics;

        Grid grid;
    };
} // namespace FEITENG
