#include "Game.hpp"

Game::Game()
{
    board_ = std::make_shared<Board>(3, 3);
    gui_ = std::make_shared<GUI>(board_);
}

void Game::GameLoop()
{
    while (!IsEndGame())
    {
        NextTurn();
    }
}

bool Game::IsEndGame()
{

    return false;
}

void Game::NextTurn()
{
   // gui_->GetNextMove(currentPlayer);
}