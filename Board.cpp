#include "Board.hpp"
#include <vector>
#include <algorithm>

#include <iostream>

Board::Board(size_t sizeX_, size_t sizeY_) : sizeX(sizeX_), sizeY(sizeY_)
{
    boardVec_ = std::vector<std::vector<char>>(sizeX_, std::vector<char>(sizeY_, '.'));
}

std::string Board::toString()
{
    std::stringstream stm;
    for (auto& row : boardVec_)
    {
        for (auto& col : row)
        {
            stm << col << " ";
        }
        stm << std::endl;
    }
    return stm.str();
}

bool Board::checkIfNumberInRow(std::vector<char>& input, char x, int number)
{
    std::string s;
    std::string toFind(number, x);
    std::transform(input.begin(), input.end(), std::back_inserter(s), [](char c) { return c; });
    size_t found = s.find(toFind);
    if (found != std::string::npos)
    {
        return true;
    }
    return false;
}

bool Board::checkWinCondition()
{
    return false;
}

std::vector<std::vector<char>> Board::getDiagonals()
{
    return {{'x','x'}};
}

bool Board::move(char player, size_t x, size_t y)
{
    if(x > sizeX or y > sizeY or boardVec_[x][y] != '.')
    {
        return false;
    } 

    boardVec_[x][y] = player;
    return true;
}




