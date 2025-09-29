#include <iostream>

#include "Game.h"
#include "Pos.h"

int main(int argc, char** argv)
{
    std::system("chcp 65001 > nul");

    std::cout << "Hello, Maze!\n" << std::endl;

    FEITENG::Game game;
    std::cout << game.getBoardInfo() << std::endl;

    std::cout << "<<<<<<<<<<<<<<<<<<<<" << std::endl;
    while(1)
    {
        std::cout << "Your Move: (u/d/l/r)" << std::endl;
        if(std::cin.eof() || std::cin.fail())
        {
            break;
        }
        std::string move, hint;
        std::cin >> move;
        switch(move[0])
        {
            case 'u':
                hint = game.move(FEITENG::Player::Heading::UP);
                break;
            case 'd':
                hint = game.move(FEITENG::Player::Heading::DOWN);
                break;
            case 'l':
                hint = game.move(FEITENG::Player::Heading::LEFT);
                break;
            case 'r':
                hint = game.move(FEITENG::Player::Heading::RIGHT);
                break;
            default:
                std::cout << "Invalid Move!" << std::endl;
                break;
        }
        std::cout << hint << '\n' << std::endl;
    }

    std::system("pause");
    return 0;
}
