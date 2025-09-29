#include "Mirror.h"

namespace FEITENG
{
    Mirror::Mirror(MirrorType type): mirror_type(type)
    {
        block_type = BlockType::MIRROR;
    }

    std::string Mirror::getName() const
    {
        return "Mirror";
    }

    void Mirror::scheduleMove(Player::Heading& heading, Pos& displacement)
    {
        switch(mirror_type)
        {
            case MirrorType::LEFT: // '\'
                switch(heading)
                {
                    case Player::Heading::UP:
                        heading = Player::Heading::LEFT;
                        displacement += { -1, 0 };
                        break;
                    case Player::Heading::DOWN:
                        heading = Player::Heading::RIGHT;
                        displacement += { 1, 0 };
                        break;
                    case Player::Heading::LEFT:
                        heading = Player::Heading::UP;
                        displacement += { 0, 1 };
                        break;
                    case Player::Heading::RIGHT:
                        heading = Player::Heading::DOWN;
                        displacement += { 0, -1 };
                        break;
                }
                break;
            case MirrorType::RIGHT: // '/'
                switch(heading)
                {
                    case Player::Heading::UP:
                        heading = Player::Heading::RIGHT;
                        displacement += { 1, 0 };
                        break;
                    case Player::Heading::DOWN:
                        heading = Player::Heading::LEFT;
                        displacement += { -1, 0 };
                        break;
                    case Player::Heading::LEFT:
                        heading = Player::Heading::DOWN;
                        displacement += { 0, -1 };
                        break;
                    case Player::Heading::RIGHT:
                        heading = Player::Heading::UP;
                        displacement += { 0, 1 };
                        break;
                }
                break;
        }
    }

    std::string Mirror::getDescription() const
    {
        return "Mirror";
    }
} // namespace FEITENG
