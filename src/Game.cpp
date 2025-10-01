#include "Game.h"

#include <sstream>

#include "MapParser.h"

namespace FEITENG
{
    Game::Game(const std::string& map_file): board(MapParser::parseFromFile(map_file))
    { }

    std::string Game::getBoardInfo() const
    {
        std::ostringstream oss;
        oss << "Board Name: " << board.getName() << '\n';
        oss << "Size: " << board.getWidth() - 2 << " * " << board.getHeight() - 2 << "\n\n";
        oss << board.getStatistics();
        return oss.str();
    }

    std::string Game::move(Player::Heading heading)
    {
        Pos displacement{ 0, 0 };
        player.heading = heading;
        switch(heading)
        {
            case Player::Heading::UP:
                displacement = { 1, 0 };
                break;
            case Player::Heading::DOWN:
                displacement = { -1, 0 };
                break;
            case Player::Heading::LEFT:
                displacement = { 0, -1 };
                break;
            case Player::Heading::RIGHT:
                displacement = { 0, 1 };
                break;
            default:
                break;
        }

        std::string hint;
        while(player.heading != Player::Heading::NONE)
        {
            board.step(player, displacement, hint);
        }
        player.pos += displacement;
        return hint;
    }
} // namespace FEITENG
