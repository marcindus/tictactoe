
#include <vector>
#include <sstream>
#include <string>

#include "Game.hpp"
#include "Board.hpp"
#include "gtest/gtest.h"

using Board = std::vector<std::vector<char>>;

std::string toString(Board& br)
{
    std::stringstream stm;
    for (auto& row : br)
    {
        for (auto& col : row)
        {
            stm << col << " ";
        }
        stm << std::endl;
    }
    return stm.str();
}

Board buildEmptyBoard(size_t size_x, size_t size_y)
{
    std::vector<std::vector<char>> vec(size_x, std::vector<char>(size_y, '.'));
    return vec;
}

bool checkIfNumberInRow(std::vector<char>& input)
{
    std::cout << input[0] << "\n";
    return true;
}


void getDiagonals(){}

struct BoardTest : public ::testing::Test
{
    Board emptyBoard3x3  = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
};

TEST_F(BoardTest, BoardShouldDoSomething)
{
    Board br = buildEmptyBoard(3, 3);
    std::cout << toString(br);

    EXPECT_EQ(br, emptyBoard3x3 );
}

TEST_F(BoardTest, shouldReturnTrueIf3InLine)
{
    EXPECT_EQ(true, checkIfNumberInRow(emptyBoard3x3[0]));
}
