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
    std::cout << std::string( 100, '\n' );
    std::cout << board_->toString();
}
