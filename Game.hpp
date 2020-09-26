#pragma once
#include "Board.hpp"
#include "GUI.hpp"
#include <memory>

enum class GameMode {
    SINGLE_PLAYER = 1,
    MULTI_PLAYER = 2
};


class Game
{
public:
Game();
void Init();
void GameLoop();
private:
TurnResult IsEndGame();
void NextTurn();
void UpdateCurrentPlayer();

std::shared_ptr<Board> board_;
std::shared_ptr<GUI> gui_;
char currentPlayer_ = 'x';
GameMode mode_ = GameMode::SINGLE_PLAYER;
};