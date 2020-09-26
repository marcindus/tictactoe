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
    bool again = false;
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
        again = gui_->PrintPlayAgainQuestion();
    } while (again);
}

TurnResult Game::IsEndGame()
{
    return board_->checkWinCondition();
}

void Game::NextTurn()
{
    gui_->update();
    if (mode_ == GameMode::SINGLE_PLAYER && currentPlayer_ == 'o')
    {
        board_->MakeBestMove(currentPlayer_);
    }
    else
    {
        gui_->GetNextMove(currentPlayer_);
    }
    gui_->update();
    UpdateCurrentPlayer();
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