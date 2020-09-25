#include "Board.hpp"
#include <vector>

Board::Board(size_t sizeX, size_t sizeY)
{
    std::vector<std::vector<char>> boardVec_(sizeX, std::vector<char>(sizeY, '.'));
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
