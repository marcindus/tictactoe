#pragma once

#include <sstream>
#include <string>
#include <vector>

class Board
{
public:
    Board(size_t sizeX_, size_t sizeY_);
    std::string toString();

private:
    size_t sizeX = 0;
    size_t sizeY = 0;
    std::vector<std::vector<char>> boardVec_;
};
