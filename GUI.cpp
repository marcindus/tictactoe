#include "GUI.hpp"
#include <iostream>

GUI::GUI()
{
    PrintInitialInformation();
}

void GUI::PrintInitialInformation()
{
    std::cout << SEPARATOR << "\n";
    std::cout << "Welcome in Tic-Tac-Toe game. \n";
}