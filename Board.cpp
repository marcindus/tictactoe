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

TurnResult Board::checkWinCondition()
{
    size_t emptyRowCnt = 3;
    for (const auto& row : boardVec_)
    {
        if (std::all_of(row.begin(), row.end(), [](const char c) { return c == 'x'; }))
        {
            return TurnResult::WIN_X;
        }
        else if (std::all_of(row.begin(), row.end(), [](const char c) { return c == 'o'; }))
        {
            return TurnResult::WIN_O;
        }
        else if (std::any_of(row.begin(), row.end(), [](const char c) { return c == '.'; }))
        {
            emptyRowCnt--;
        }
    }

    if (boardVec_[0][0] == 'x' && boardVec_[1][1] == 'x' && boardVec_[2][2] == 'x'
        || boardVec_[2][0] == 'x' && boardVec_[1][1] == 'x' && boardVec_[0][2] == 'x')
    {
        return TurnResult::WIN_X;
    }
    else if (boardVec_[0][0] == 'o' && boardVec_[1][1] == 'o' && boardVec_[2][2] == 'o'
             || boardVec_[2][0] == 'o' && boardVec_[1][1] == 'o' && boardVec_[0][2] == 'o')
    {
        return TurnResult::WIN_O;
    }
    else if (emptyRowCnt == 0)
    {
        return TurnResult::DRAW;
    }

    return TurnResult::NO_RESULT;
}

std::vector<std::vector<char>> Board::getDiagonals()
{
    return {{'x', 'x'}};
}

bool Board::move(char player, size_t x, size_t y)
{
    if (x > sizeX or y > sizeY or boardVec_[x][y] != '.')
    {
        return false;
    }

    boardVec_[x][y] = player;
    return true;
}
