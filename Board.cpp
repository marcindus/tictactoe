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
        else if (std::none_of(row.begin(), row.end(), [](const char c) { return c == '.'; }))
        {
            emptyRowCnt--;
        }
    }
    if (IsDiagonalsAll('x') || IsColumnsAll('x'))
    {
        return TurnResult::WIN_X;
    }
    else if (IsDiagonalsAll('o') || IsColumnsAll('o'))
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

bool Board::IsDiagonalsAll(char player)
{
    return (boardVec_[0][0] == player && boardVec_[1][1] == player && boardVec_[2][2] == player
            || boardVec_[2][0] == player && boardVec_[1][1] == player && boardVec_[0][2] == player);
}

bool Board::IsColumnsAll(char player)
{
    return (boardVec_[0][0] == player && boardVec_[1][0] == player && boardVec_[2][0] == player
            || boardVec_[0][1] == player && boardVec_[1][1] == player && boardVec_[2][1] == player
            || boardVec_[0][2] == player && boardVec_[1][2] == player && boardVec_[2][2] == player);
}
