#include "Game.hpp"

Game::Game()
{
    board_ = std::make_shared<Board>(3, 3);
    gui_ = std::make_shared<GUI>(board_);
}

void Game::Init()
{
    mode_ = gui_->GetGameMode();
    GameLoop();
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
    return board_->checkWinCondition();
}

void Game::NextTurn()
{
    if (mode_ == GameMode::SINGLE_PLAYER && currentPlayer_ == 'o')
    {
        // board_->MakeBestMove();
    }
    else
    {
        gui_->GetNextMove(currentPlayer_);
    }
    UpdateCurrentPlayer();
    gui_->update();
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