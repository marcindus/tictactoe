#pragma once

#include <sstream>
#include <string>
#include <vector>

class Board
{
public:
    Board(size_t sizeX_, size_t sizeY_);
    std::string toString();
    std::vector<std::vector<char>> GetBoardVec() { return boardVec_; }
    bool checkWinCondition();
    bool move(char player, size_t x, size_t y);

private:
    size_t sizeX = 0;
    size_t sizeY = 0;
    std::vector<std::vector<char>> boardVec_;
    bool checkIfNumberInRow(std::vector<char>& input, char x, int number);
    std::vector<std::vector<char>> getDiagonals();
};
