#include "Board.hpp"
#include <vector>

Board::Board(size_t sizeX, size_t sizeY)
{
    std::vector<std::vector<char>> board_(sizeX, std::vector<char>(sizeY, '.'));
}