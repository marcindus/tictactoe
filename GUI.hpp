#pragma once
#include <string>
#include <memory>
#include "Board.hpp"

enum class GameMode;

static const std::string SEPARATOR("*", 35);

class GUI
{
public:
    GUI(std::shared_ptr<Board> board);
    void update();
    void GetNextMove(char player);
    GameMode GetGameMode();
    void PrintResult(TurnResult result);
    bool PrintPlayAgainQuestion();

private:
    void PrintInitialInformation();
    std::shared_ptr<Board> board_;
};
