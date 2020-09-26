#include "GUI.hpp"
#include "Game.hpp"
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
    while (!status)
    {
        std::cout << "Player " << player << "Enter next move: " << std::endl << "x : " << std::endl;
        std::cin >> x;
        std::cout << "y :";
        std::cin >> y;
        status = board_->move(player, x, y);
    }
}

GameMode GUI::GetGameMode()
{
    size_t mode = 0;
    std::cout << "Please select game mode:\n"
                 "1) Single player (with AI)\n"
                 "2) Multiplayer (with second person)\n";
    while (mode < static_cast<size_t>(GameMode::SINGLE_PLAYER) || 
           mode > static_cast<size_t>(GameMode::MULTI_PLAYER))
    {
        std::cin >> mode;
    }

    return static_cast<GameMode>(mode);
}