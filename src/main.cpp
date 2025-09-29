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
        std::string move;
        std::cin >> move;
        FEITENG::Pos direction;
        switch(move[0])
        {
            case 'u':
                direction = { 0, 1 };
                break;
            case 'd':
                direction = { 0, -1 };
                break;
            case 'l':
                direction = { -1, 0 };
                break;
            case 'r':
                direction = { 1, 0 };
                break;
            default:
                break;
        }
        game.move(direction);
        std::cout << game.getHint() << '\n' << std::endl;
    }

    std::system("pause");
    return 0;
}
