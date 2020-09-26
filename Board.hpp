#pragma once

#include <sstream>
#include <string>
#include <vector>

enum class TurnResult
{
    WIN_X = 0,
    WIN_O = 1,
    DRAW = 2,
    NO_RESULT = 3
};

class Board
{
public:
    Board(size_t sizeX_, size_t sizeY_);
    std::string toString();
    std::vector<std::vector<char>> GetBoardVec() { return boardVec_; }
    TurnResult checkWinCondition();
    bool move(char player, size_t x, size_t y);
    void Clear();

private:
    size_t sizeX = 0;
    size_t sizeY = 0;
    std::vector<std::vector<char>> boardVec_;
    bool checkIfNumberInRow(std::vector<char>& input, char x, int number);
    bool IsDiagonalsAll(char player);
    bool IsColumnsAll(char player);
    std::vector<std::vector<char>> getDiagonals();
};
