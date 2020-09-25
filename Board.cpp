#include "Board.hpp"
#include <vector>

#include <iostream>

Board::Board(size_t sizeX_, size_t sizeY_) : sizeX(sizeX_), sizeY(sizeY_)
{
    std::vector<std::vector<char>> boardtmp_(sizeX_, std::vector<char>(sizeY_, '.'));
    board_ = boardtmp_;
}

std::string Board::toString()
{
    std::stringstream stm;
    for (auto& row : board_)
    {
        for (auto& col : row)
        {
            stm << col << " ";
        }
        stm << std::endl;
    }
    return stm.str();
}


