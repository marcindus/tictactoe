#pragma once
#include <string>
#include <memory>
#include "Board.hpp"

enum class GameMode;

static const std::string SEPARATOR;

class GUI
{
public:
    GUI(std::shared_ptr<Board> board);
    void update();
    void GetNextMove(char player);
    GameMode GetGameMode();

private:
    void PrintInitialInformation();
    std::shared_ptr<Board> board_;
};
