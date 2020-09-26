#include "Game.hpp"

Game::Game()
{
    board_ = std::make_shared<Board>(3, 3);
    gui_ = std::make_shared<GUI>(board_);
}

void Game::Init()
{
    GameLoop();
}

void Game::GameLoop()
{
    do
    {
        board_->Clear();
        mode_ = gui_->GetGameMode();
        TurnResult result = TurnResult::NO_RESULT;
        while (result == TurnResult::NO_RESULT)
        {
            NextTurn();
            result = IsEndGame();
        }
        gui_->PrintResult(result);
        bool again = gui_->PrintPlayAgainQuestion();
    } while (again);
}

TurnResult Game::IsEndGame()
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