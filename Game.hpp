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

std::shared_ptr<Board> board_;
std::shared_ptr<GUI> gui_;
};