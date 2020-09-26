#include "GUI.hpp"
#include <string>
#include <iostream>

GUI::GUI(std::shared_ptr<Board> board) : board_(board)
{
    PrintInitialInformation();
}

void GUI::PrintInitialInformation()
{
    std::cout << SEPARATOR << "\n";
    std::cout << "Welcome in Tic-Tac-Toe game. \n";
}

void GUI::update()
{
    std::cout << std::string(100, '\n');
    std::cout << board_->toString();
}
void GUI::GetNextMove(char player)
{
    size_t x = 0;
    size_t y = 0;

    bool status = false;
    while(!status)
    {
        std::cout << "Player " << player << "Enter next move: " << std::endl << "x : " << std::endl;
        std::cin >> x;
        std::cout << "y :";
        std::cin >> y;
        status = board_->move(player,x,y);
    }
}
