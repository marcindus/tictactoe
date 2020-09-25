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
    if (board_->checkWinCondition())
    {
        return true;
    }
}

void Game::NextTurn()
{
    // gui_->GetNextMove(currentPlayer_);
    // UpdateCurrentPlayer();
}

void Game::UpdateCurrentPlayer()
{
    if (currentPlayer_ == 'x')
    {
        currentPlayer_ = 'o';
    }
    else
    {
        currentPlayer_ = 'x';
    }
}