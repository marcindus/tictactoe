#pragma once
#include "Board.hpp"
#include "GUI.hpp"
#include <memory>

class Game
{
public:
Game();
void GameLoop();
private:
bool IsEndGame();
void NextTurn();

std::shared_ptr<Board> board_;
std::shared_ptr<GUI> gui_;
char currentPlayer = 'x';
};