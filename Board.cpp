#include "Board.hpp"
#include <vector>

Board::Board(size_t sizeX, size_t sizeY)
{
    std::vector<std::vector<char>> board_(sizeX, std::vector<char>(sizeY, '.'));
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


